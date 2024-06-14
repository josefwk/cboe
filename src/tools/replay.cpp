#include "replay.hpp"

// Input recording system

#include "ticpp.h"
#include <ctime>
#include <iomanip>
#include <fstream>
#include <boost/algorithm/string/predicate.hpp>
#include <cppcodec/base64_rfc4648.hpp>
using base64 = cppcodec::base64_rfc4648;

bool recording = false;
bool replaying = false;

using namespace ticpp;
Document log_document;
std::string log_file;

bool init_action_log(std::string command, std::string file) {
	if (command == "record") {
		// If a filename is given, use it as a base, but insert a timestamp for uniqueness.
		if (file.empty())
			file = "BoE";

		if (boost::ends_with(file, ".xml"))
			file = file.substr(0, file.length() - 4);

		// Get a time stamp
		std::time_t t = time(nullptr);
		auto tm = *std::localtime(&t);
		std::ostringstream stream;
		stream << file << std::put_time(&tm, "_%d-%m-%Y_%H-%M-%S") << ".xml";
		log_file = stream.str();
		
		try {
			Element root_element("actions");
			log_document.InsertEndChild(root_element);
			log_document.SaveFile(log_file);
			recording = true;
			std::cout << "Recording this session: " << log_file << std::endl;
		} catch(...) {
			std::cout << "Failed to write to file " << log_file << std::endl;
		}
		return true;
	}
	else if (command == "replay") {
		try {
			log_document.LoadFile(file);
			replaying = true;
		} catch(...) {
			std::cout << "Failed to load file " << file << std::endl;
		}
		return true;
	}
	return false;
}

void record_action(std::string action_type, std::string inner_text) {
	Element* root = log_document.FirstChildElement();
	Element next_action(action_type);
	Text action_text(inner_text);
	next_action.InsertEndChild(action_text);
	root->InsertEndChild(next_action);
	log_document.SaveFile(log_file);
}

bool has_next_action() {
	Element* root = log_document.FirstChildElement();
	return root->FirstChildElement(false) != NULL;
}

Element* pop_next_action(std::string expected_action_type) {
	Element* root = log_document.FirstChildElement();
	Element* next_action = root->FirstChildElement();
	
	if (expected_action_type != "" && next_action->Value() != expected_action_type) {
		std::ostringstream stream;
		stream << "Replay error! Expected '" << expected_action_type << "' action next";
		throw stream.str();
	}

	Element* clone = next_action->Clone()->ToElement();
	root->RemoveChild(next_action);
	
	return clone;
}

std::string encode_file(fs::path file) {
	std::ifstream ifs(file.string(), std::ios::binary|std::ios::ate);
    std::ifstream::pos_type pos = ifs.tellg();

    std::vector<char> result(pos);

    ifs.seekg(0, std::ios::beg);
    ifs.read(result.data(), pos);

    return base64::encode(result.data(), result.size() * sizeof(char));
}

void decode_file(std::string data, fs::path file) {
	std::ofstream ofs(file.string(), std::ios::binary|std::ios::ate);
	std::vector<uint8_t> bytes = base64::decode(data.c_str(), strlen(data.c_str()) * sizeof(char));
	char* bytes_as_c_str = reinterpret_cast<char*>(bytes.data());
	ofs.write(bytes_as_c_str, bytes.size() / sizeof(char));
}