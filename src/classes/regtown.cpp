/*
 *  regtown.cpp
 *  BoE
 *
 *  Created by Celtic Minstrel on 24/04/09.
 *
 */

#include "regtown.h"

#include <string>
#include <vector>
#include <map>
#include <sstream>

#include "scenario.h"
#include "dlogutil.hpp"
#include "oldstructs.h"
#include "fileio.hpp"

void cTinyTown::append(legacy::tiny_tr_type& old, int town_num){
	int i,j;
	cField the_field;
	the_field.type = SPECIAL_SPOT;
	// Collect a list of unused special nodes, to be used for fixing specials that could be triggered in a boat.
	std::vector<int> unused_special_slots;
	for(i = 0; i < 100; i++) {
		if(specials[i].type == eSpecType::NONE && specials[i].jumpto == -1) {
			// Also make sure no specials jump to it
			bool is_free = true;
			for(j = 0; j < 100; j++) {
				if(specials[j].jumpto == i) is_free = false;
			}
			if(is_free) unused_special_slots.push_back(i);
		}
	}
	for(i = 0; i < 32; i++)
		for(j = 0; j < 32; j++) {
			ter[i][j] = old.terrain[i][j];
			light[i / 8][j] = old.lighting[i / 8][j];
			if(scenario.ter_types[ter[i][j]].i == 3000) { // marker to indicate it used to be a special spot
				the_field.loc.x = i;
				the_field.loc.y = j;
				preset_fields.push_back(the_field);
			}
			if(scenario.ter_types[ter[i][j]].boat_over) {
				// Try to fix specials that could be triggered while in a boat
				// (Boats never triggered specials in the old BoE, so we probably don't want them to trigger.)
				int found_spec = -1;
				for(int k = 0; k < 50; k++) {
					if(i == special_locs[k].x && j == special_locs[k].y) {
						found_spec = k;
						break;
					}
				}
				if(found_spec >= 0) {
					if(!unused_special_slots.empty()) {
						int found_spec_id = spec_id[found_spec], use_slot = unused_special_slots.back();
						unused_special_slots.pop_back();
						cSpecial& node = specials[use_slot];
						node.type = eSpecType::IF_CONTEXT;
						node.ex1a = 101; // if in boat
						node.ex1c = -1; // do nothing
						node.jumpto = found_spec_id; // else jump here
						spec_id[found_spec] = use_slot;
					} else {
						std::stringstream sout;
						sout << "In town \"" << town_num << "\" at (" << i << ',' << j << "); special node ID " << spec_id[found_spec];
						giveError("Warning: A special node was found that could be triggered from in a boat, which is probably not what the designer intended. An attempt to fix this has failed because there were not enough unused special nodes.", sout.str());
					}
				}
			}
		}
	for(i = 0; i < 16; i++) {
		room_rect[i].top = old.room_rect[i].top;
		room_rect[i].left = old.room_rect[i].left;
		room_rect[i].bottom = old.room_rect[i].bottom;
		room_rect[i].right = old.room_rect[i].right;
	}
	creatures.resize(30);
	for(i = 0; i < 30; i++) {
		creatures[i].append(old.creatures[i]);
	}
}

void cMedTown::append(legacy::ave_tr_type& old, int town_num){
	int i,j;
	cField the_field;
	the_field.type = SPECIAL_SPOT;
	// Collect a list of unused special nodes, to be used for fixing specials that could be triggered in a boat.
	std::vector<int> unused_special_slots;
	for(i = 0; i < 100; i++) {
		if(specials[i].type == eSpecType::NONE && specials[i].jumpto == -1) {
			// Also make sure no specials jump to it
			bool is_free = true;
			for(j = 0; j < 100; j++) {
				if(specials[j].jumpto == i) is_free = false;
			}
			if(is_free) unused_special_slots.push_back(i);
		}
	}
	for(i = 0; i < 48; i++)
		for(j = 0; j < 48; j++) {
			ter[i][j] = old.terrain[i][j];
			light[i / 8][j] = old.lighting[i / 8][j];
			if(scenario.ter_types[ter[i][j]].i == 3000) { // marker to indicate it used to be a special spot
				the_field.loc.x = i;
				the_field.loc.y = j;
				preset_fields.push_back(the_field);
			}
			if(scenario.ter_types[ter[i][j]].boat_over) {
				// Try to fix specials that could be triggered while in a boat
				// (Boats never triggered specials in the old BoE, so we probably don't want them to trigger.)
				int found_spec = -1;
				for(int k = 0; k < 50; k++) {
					if(i == special_locs[k].x && j == special_locs[k].y) {
						found_spec = k;
						break;
					}
				}
				if(found_spec >= 0) {
					if(!unused_special_slots.empty()) {
						int found_spec_id = spec_id[found_spec], use_slot = unused_special_slots.back();
						unused_special_slots.pop_back();
						cSpecial& node = specials[use_slot];
						node.type = eSpecType::IF_CONTEXT;
						node.ex1a = 101; // if in boat
						node.ex1c = -1; // do nothing
						node.jumpto = found_spec_id; // else jump here
						spec_id[found_spec] = use_slot;
					} else {
						std::stringstream sout;
						sout << "In town " << town_num << " at (" << i << ',' << j << "); special node ID " << spec_id[found_spec];
						giveError("Warning: A special node was found that could be triggered from in a boat, which is probably not what the designer intended. An attempt to fix this has failed because there were not enough unused special nodes.", sout.str());
					}
				}
			}
		}
	for(i = 0; i < 16; i++) {
		room_rect[i].top = old.room_rect[i].top;
		room_rect[i].left = old.room_rect[i].left;
		room_rect[i].bottom = old.room_rect[i].bottom;
		room_rect[i].right = old.room_rect[i].right;
	}
	creatures.resize(40);
	for(i = 0; i < 40; i++) {
		creatures[i].append(old.creatures[i]);
	}
}

void cBigTown::append(legacy::big_tr_type& old, int town_numo){
	int i,j;
	cField the_field;
	the_field.type = SPECIAL_SPOT;
	// Collect a list of unused special nodes, to be used for fixing specials that could be triggered in a boat.
	std::vector<int> unused_special_slots;
	for(i = 0; i < 100; i++) {
		if(specials[i].type == eSpecType::NONE && specials[i].jumpto == -1) {
			// Also make sure no specials jump to it
			bool is_free = true;
			for(j = 0; j < 100; j++) {
				if(specials[j].jumpto == i) is_free = false;
			}
			if(is_free) unused_special_slots.push_back(i);
		}
	}
	for(i = 0; i < 64; i++)
		for(j = 0; j < 64; j++) {
			ter[i][j] = old.terrain[i][j];
			light[i / 8][j] = old.lighting[i / 8][j];
			if(scenario.ter_types[ter[i][j]].i == 3000) { // marker to indicate it used to be a special spot
				the_field.loc.x = i;
				the_field.loc.y = j;
				preset_fields.push_back(the_field);
			}
			if(scenario.ter_types[ter[i][j]].boat_over) {
				// Try to fix specials that could be triggered while in a boat
				// (Boats never triggered specials in the old BoE, so we probably don't want them to trigger.)
				int found_spec = -1;
				for(int k = 0; k < 50; k++) {
					if(i == special_locs[k].x && j == special_locs[k].y) {
						found_spec = k;
						break;
					}
				}
				if(found_spec >= 0) {
					if(!unused_special_slots.empty()) {
						int found_spec_id = spec_id[found_spec], use_slot = unused_special_slots.back();
						unused_special_slots.pop_back();
						cSpecial& node = specials[use_slot];
						node.type = eSpecType::IF_CONTEXT;
						node.ex1a = 101; // if in boat
						node.ex1c = -1; // do nothing
						node.jumpto = found_spec_id; // else jump here
						spec_id[found_spec] = use_slot;
					} else {
						std::stringstream sout;
						sout << "In town " << town_numo << " at (" << i << ',' << j << "); special node ID " << spec_id[found_spec];
						giveError("Warning: A special node was found that could be triggered from in a boat, which is probably not what the designer intended. An attempt to fix this has failed because there were not enough unused special nodes.", sout.str());
					}
				}
			}
		}
	for(i = 0; i < 16; i++) {
		room_rect[i].top = old.room_rect[i].top;
		room_rect[i].left = old.room_rect[i].left;
		room_rect[i].bottom = old.room_rect[i].bottom;
		room_rect[i].right = old.room_rect[i].right;
	}
	creatures.resize(60);
	for(i = 0; i < 60; i++) {
		creatures[i].append(old.creatures[i]);
	}
}

ter_num_t& cTinyTown::terrain(size_t x, size_t y){
	return ter[x][y];
}

void cTinyTown::writeTerrainTo(std::ostream& file) {
	writeArray(file, ter, 32, 32);
}

void cTinyTown::readTerrainFrom(std::istream& file) {
	readArray(file, ter, 32, 32);
}

unsigned char& cTinyTown::lighting(size_t i, size_t r){
	return light[i][r];
}

ter_num_t& cMedTown::terrain(size_t x, size_t y){
	return ter[x][y];
}

void cMedTown::writeTerrainTo(std::ostream& file) {
	writeArray(file, ter, 48, 48);
}

void cMedTown::readTerrainFrom(std::istream& file) {
	readArray(file, ter, 48, 48);
}

unsigned char& cMedTown::lighting(size_t i, size_t r){
	return light[i][r];
}

ter_num_t& cBigTown::terrain(size_t x, size_t y){
	return ter[x][y];
}

void cBigTown::writeTerrainTo(std::ostream& file) {
	writeArray(file, ter, 64, 64);
}

void cBigTown::readTerrainFrom(std::istream& file) {
	readArray(file, ter, 64, 64);
}

unsigned char& cBigTown::lighting(size_t i, size_t r){
	return light[i][r];
}

cBigTown::cBigTown(cScenario& scenario, bool init_strings) : cTown(scenario, init_strings) {
	for(size_t i = 0; i < max_dim(); i++)
		for(size_t j = 0; j < max_dim(); j++) {
			terrain(i,j) = scenario.default_ground * 2;
			lighting(i / 8,j) = 0;
		}
	init_start();
}

cMedTown::cMedTown(cScenario& scenario, bool init_strings) : cTown(scenario, init_strings) {
	for(size_t i = 0; i < max_dim(); i++)
		for(size_t j = 0; j < max_dim(); j++) {
			terrain(i,j) = scenario.default_ground * 2;
			lighting(i / 8,j) = 0;
		}
	init_start();
}

cTinyTown::cTinyTown(cScenario& scenario, bool init_strings) : cTown(scenario, init_strings) {
	for(size_t i = 0; i < max_dim(); i++)
		for(size_t j = 0; j < max_dim(); j++) {
			terrain(i,j) = scenario.default_ground * 2;
			lighting(i / 8,j) = 0;
		}
	init_start();
}

size_t cBigTown::max_dim() const {
	return 64;
}

size_t cMedTown::max_dim() const {
	return 48;
}

size_t cTinyTown::max_dim() const {
	return 32;
}
