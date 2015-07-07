//
//  oldstructs.cpp
//  BoE
//
//  Created by Celtic Minstrel on 14-12-02.
//
//

#include "oldstructs.hpp"
#include <fstream>
#include <iostream>
#ifndef _WIN32
#include <unistd.h>
#endif

using namespace legacy;

#define STRUCT_INFO(what) \
	what temp_##what; \
	log << #what << ": " << sizeof(temp_##what) << " bytes" << std::endl
#define MEM_INFO(what,member) \
	log << "   " << #member << ": " << sizeof(temp_##what . member) << " bytes, offset " \
		<< offsetof(what,member) << std::endl

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4101)
#endif

// This is just a function to output all known information about each struct and its members.
void debug_oldstructs(); // Suppress "no prototype" warning
void debug_oldstructs() {
#ifndef _WIN32
	char cwd[256];
	getcwd(cwd, 256);
	std::cout << cwd << std::endl;
#endif
	std::ofstream log("oldstructs.txt");
	STRUCT_INFO(Rect);
	MEM_INFO(Rect,top);
	MEM_INFO(Rect,left);
	MEM_INFO(Rect,bottom);
	MEM_INFO(Rect,right);
	STRUCT_INFO(Boolean);
	STRUCT_INFO(location);
	MEM_INFO(location,x);
	MEM_INFO(location,y);
	STRUCT_INFO(special_node_type);
	MEM_INFO(special_node_type,type);
	MEM_INFO(special_node_type,sd1);
	MEM_INFO(special_node_type,sd2);
	MEM_INFO(special_node_type,pic);
	MEM_INFO(special_node_type,m1);
	MEM_INFO(special_node_type,m2);
	MEM_INFO(special_node_type,ex1a);
	MEM_INFO(special_node_type,ex1b);
	MEM_INFO(special_node_type,ex2a);
	MEM_INFO(special_node_type,ex2b);
	MEM_INFO(special_node_type,jumpto);
	STRUCT_INFO(talking_node_type);
	MEM_INFO(talking_node_type,personality);
	MEM_INFO(talking_node_type,type);
	MEM_INFO(talking_node_type,link1);
	MEM_INFO(talking_node_type,link2);
	MEM_INFO(talking_node_type,extras);
	STRUCT_INFO(talking_record_type);
	MEM_INFO(talking_record_type,strlens);
	MEM_INFO(talking_record_type,talk_nodes);
	STRUCT_INFO(terrain_type_type);
	MEM_INFO(terrain_type_type,picture);
	MEM_INFO(terrain_type_type,blockage);
	MEM_INFO(terrain_type_type,flag1);
	MEM_INFO(terrain_type_type,flag2);
	MEM_INFO(terrain_type_type,special);
	MEM_INFO(terrain_type_type,trans_to_what);
	MEM_INFO(terrain_type_type,fly_over);
	MEM_INFO(terrain_type_type,boat_over);
	MEM_INFO(terrain_type_type,block_horse);
	MEM_INFO(terrain_type_type,light_radius);
	MEM_INFO(terrain_type_type,step_sound);
	MEM_INFO(terrain_type_type,shortcut_key);
	MEM_INFO(terrain_type_type,res1);
	MEM_INFO(terrain_type_type,res2);
	MEM_INFO(terrain_type_type,res3);
	STRUCT_INFO(wandering_type);
	MEM_INFO(wandering_type,monst);
	STRUCT_INFO(out_wandering_type);
	MEM_INFO(out_wandering_type,monst);
	MEM_INFO(out_wandering_type,friendly);
	MEM_INFO(out_wandering_type,spec_on_meet);
	MEM_INFO(out_wandering_type,spec_on_win);
	MEM_INFO(out_wandering_type,spec_on_flee);
	MEM_INFO(out_wandering_type,cant_flee);
	MEM_INFO(out_wandering_type,end_spec1);
	MEM_INFO(out_wandering_type,end_spec2);
	STRUCT_INFO(outdoor_record_type);
	MEM_INFO(outdoor_record_type,terrain);
	MEM_INFO(outdoor_record_type,special_locs);
	MEM_INFO(outdoor_record_type,special_id);
	MEM_INFO(outdoor_record_type,exit_locs);
	MEM_INFO(outdoor_record_type,exit_dests);
	MEM_INFO(outdoor_record_type,sign_locs);
	MEM_INFO(outdoor_record_type,wandering);
	MEM_INFO(outdoor_record_type,special_enc);
	MEM_INFO(outdoor_record_type,wandering_locs);
	MEM_INFO(outdoor_record_type,info_rect);
	MEM_INFO(outdoor_record_type,strlens);
	MEM_INFO(outdoor_record_type,specials);
	STRUCT_INFO(creature_start_type);
	MEM_INFO(creature_start_type,number);
	MEM_INFO(creature_start_type,start_attitude);
	MEM_INFO(creature_start_type,start_loc);
	MEM_INFO(creature_start_type,mobile);
	MEM_INFO(creature_start_type,time_flag);
	MEM_INFO(creature_start_type,extra1);
	MEM_INFO(creature_start_type,extra2);
	MEM_INFO(creature_start_type,spec1);
	MEM_INFO(creature_start_type,spec2);
	MEM_INFO(creature_start_type,spec_enc_code);
	MEM_INFO(creature_start_type,time_code);
	MEM_INFO(creature_start_type,monster_time);
	MEM_INFO(creature_start_type,personality);
	MEM_INFO(creature_start_type,special_on_kill);
	MEM_INFO(creature_start_type,facial_pic);
	STRUCT_INFO(short_item_record_type);
	MEM_INFO(short_item_record_type,variety);
	MEM_INFO(short_item_record_type,item_level);
	MEM_INFO(short_item_record_type,awkward);
	MEM_INFO(short_item_record_type,bonus);
	MEM_INFO(short_item_record_type,protection);
	MEM_INFO(short_item_record_type,charges);
	MEM_INFO(short_item_record_type,type);
	MEM_INFO(short_item_record_type,graphic_num);
	MEM_INFO(short_item_record_type,ability);
	MEM_INFO(short_item_record_type,type_flag);
	MEM_INFO(short_item_record_type,is_special);
	MEM_INFO(short_item_record_type,value);
	MEM_INFO(short_item_record_type,identified);
	MEM_INFO(short_item_record_type,magic);
	MEM_INFO(short_item_record_type,weight);
	MEM_INFO(short_item_record_type,description_flag);
	MEM_INFO(short_item_record_type,full_name);
	MEM_INFO(short_item_record_type,name);
	MEM_INFO(short_item_record_type,reserved1);
	MEM_INFO(short_item_record_type,reserved2);
	MEM_INFO(short_item_record_type,magic_use_type);
	MEM_INFO(short_item_record_type,ability_strength);
	MEM_INFO(short_item_record_type,treas_class);
	MEM_INFO(short_item_record_type,real_abil);
	STRUCT_INFO(item_record_type);
	MEM_INFO(item_record_type,variety);
	MEM_INFO(item_record_type,item_level);
	MEM_INFO(item_record_type,awkward);
	MEM_INFO(item_record_type,bonus);
	MEM_INFO(item_record_type,protection);
	MEM_INFO(item_record_type,charges);
	MEM_INFO(item_record_type,type);
	MEM_INFO(item_record_type,magic_use_type);
	MEM_INFO(item_record_type,graphic_num);
	MEM_INFO(item_record_type,ability);
	MEM_INFO(item_record_type,ability_strength);
	MEM_INFO(item_record_type,type_flag);
	MEM_INFO(item_record_type,is_special);
	MEM_INFO(item_record_type,value);
	MEM_INFO(item_record_type,weight);
	MEM_INFO(item_record_type,special_class);
	MEM_INFO(item_record_type,item_loc);
	MEM_INFO(item_record_type,full_name);
	MEM_INFO(item_record_type,name);
	MEM_INFO(item_record_type,treas_class);
	MEM_INFO(item_record_type,item_properties);
	MEM_INFO(item_record_type,reserved1);
	MEM_INFO(item_record_type,reserved2);
	STRUCT_INFO(preset_item_type);
	MEM_INFO(preset_item_type,item_loc);
	MEM_INFO(preset_item_type,item_code);
	MEM_INFO(preset_item_type,ability);
	MEM_INFO(preset_item_type,charges);
	MEM_INFO(preset_item_type,always_there);
	MEM_INFO(preset_item_type,property);
	MEM_INFO(preset_item_type,contained);
	STRUCT_INFO(preset_field_type);
	MEM_INFO(preset_field_type,field_loc);
	MEM_INFO(preset_field_type,field_type);
	STRUCT_INFO(town_record_type);
	MEM_INFO(town_record_type,town_chop_time);
	MEM_INFO(town_record_type,town_chop_key);
	MEM_INFO(town_record_type,wandering);
	MEM_INFO(town_record_type,wandering_locs);
	MEM_INFO(town_record_type,special_locs);
	MEM_INFO(town_record_type,spec_id);
	MEM_INFO(town_record_type,sign_locs);
	MEM_INFO(town_record_type,lighting);
	MEM_INFO(town_record_type,start_locs);
	MEM_INFO(town_record_type,exit_locs);
	MEM_INFO(town_record_type,exit_specs);
	MEM_INFO(town_record_type,in_town_rect);
	MEM_INFO(town_record_type,preset_items);
	MEM_INFO(town_record_type,max_num_monst);
	MEM_INFO(town_record_type,preset_fields);
	MEM_INFO(town_record_type,spec_on_entry);
	MEM_INFO(town_record_type,spec_on_entry_if_dead);
	MEM_INFO(town_record_type,timer_spec_times);
	MEM_INFO(town_record_type,timer_specs);
	MEM_INFO(town_record_type,strlens);
	MEM_INFO(town_record_type,specials);
	MEM_INFO(town_record_type,specials1);
	MEM_INFO(town_record_type,specials2);
	MEM_INFO(town_record_type,res1);
	MEM_INFO(town_record_type,res2);
	MEM_INFO(town_record_type,difficulty);
	STRUCT_INFO(big_tr_type);
	MEM_INFO(big_tr_type,terrain);
	MEM_INFO(big_tr_type,room_rect);
	MEM_INFO(big_tr_type,creatures);
	MEM_INFO(big_tr_type,lighting);
	STRUCT_INFO(ave_tr_type);
	MEM_INFO(ave_tr_type,terrain);
	MEM_INFO(ave_tr_type,room_rect);
	MEM_INFO(ave_tr_type,creatures);
	MEM_INFO(ave_tr_type,lighting);
	STRUCT_INFO(tiny_tr_type);
	MEM_INFO(tiny_tr_type,terrain);
	MEM_INFO(tiny_tr_type,room_rect);
	MEM_INFO(tiny_tr_type,creatures);
	MEM_INFO(tiny_tr_type,lighting);
	STRUCT_INFO(city_block_type);
	MEM_INFO(city_block_type,block_type);
	MEM_INFO(city_block_type,block_destroy_time);
	MEM_INFO(city_block_type,block_alignment);
	MEM_INFO(city_block_type,block_key_time);
	MEM_INFO(city_block_type,block_loc);
	STRUCT_INFO(city_ter_rect_type);
	MEM_INFO(city_ter_rect_type,what_rect);
	MEM_INFO(city_ter_rect_type,ter_type);
	MEM_INFO(city_ter_rect_type,hollow);
	STRUCT_INFO(template_town_type);
	MEM_INFO(template_town_type,creatures);
	MEM_INFO(template_town_type,city_block);
	MEM_INFO(template_town_type,city_ter_rect);
	STRUCT_INFO(scen_item_data_type);
	MEM_INFO(scen_item_data_type,scen_items);
	MEM_INFO(scen_item_data_type,monst_names);
	MEM_INFO(scen_item_data_type,ter_names);
	STRUCT_INFO(item_storage_shortcut_type);
	MEM_INFO(item_storage_shortcut_type,ter_type);
	MEM_INFO(item_storage_shortcut_type,item_num);
	MEM_INFO(item_storage_shortcut_type,item_odds);
	MEM_INFO(item_storage_shortcut_type,property);
	STRUCT_INFO(monster_record_type);
	MEM_INFO(monster_record_type,m_num);
	MEM_INFO(monster_record_type,level);
	MEM_INFO(monster_record_type,m_name);
	MEM_INFO(monster_record_type,health);
	MEM_INFO(monster_record_type,m_health);
	MEM_INFO(monster_record_type,mp);
	MEM_INFO(monster_record_type,max_mp);
	MEM_INFO(monster_record_type,armor);
	MEM_INFO(monster_record_type,skill);
	MEM_INFO(monster_record_type,a);
	MEM_INFO(monster_record_type,a1_type);
	MEM_INFO(monster_record_type,a23_type);
	MEM_INFO(monster_record_type,m_type);
	MEM_INFO(monster_record_type,speed);
	MEM_INFO(monster_record_type,ap);
	MEM_INFO(monster_record_type,mu);
	MEM_INFO(monster_record_type,cl);
	MEM_INFO(monster_record_type,breath);
	MEM_INFO(monster_record_type,breath_type);
	MEM_INFO(monster_record_type,treasure);
	MEM_INFO(monster_record_type,spec_skill);
	MEM_INFO(monster_record_type,poison);
	MEM_INFO(monster_record_type,morale);
	MEM_INFO(monster_record_type,m_morale);
	MEM_INFO(monster_record_type,corpse_item);
	MEM_INFO(monster_record_type,corpse_item_chance);
	MEM_INFO(monster_record_type,status);
	MEM_INFO(monster_record_type,direction);
	MEM_INFO(monster_record_type,immunities);
	MEM_INFO(monster_record_type,x_width);
	MEM_INFO(monster_record_type,y_width);
	MEM_INFO(monster_record_type,radiate_1);
	MEM_INFO(monster_record_type,radiate_2);
	MEM_INFO(monster_record_type,default_attitude);
	MEM_INFO(monster_record_type,summon_type);
	MEM_INFO(monster_record_type,default_facial_pic);
	MEM_INFO(monster_record_type,res1);
	MEM_INFO(monster_record_type,res2);
	MEM_INFO(monster_record_type,res3);
	MEM_INFO(monster_record_type,picture_num);
	STRUCT_INFO(horse_record_type);
	MEM_INFO(horse_record_type,horse_loc);
	MEM_INFO(horse_record_type,horse_loc_in_sec);
	MEM_INFO(horse_record_type,horse_sector);
	MEM_INFO(horse_record_type,which_town);
	MEM_INFO(horse_record_type,exists);
	MEM_INFO(horse_record_type,property);
	STRUCT_INFO(boat_record_type);
	MEM_INFO(boat_record_type,boat_loc);
	MEM_INFO(boat_record_type,boat_loc_in_sec);
	MEM_INFO(boat_record_type,boat_sector);
	MEM_INFO(boat_record_type,which_town);
	MEM_INFO(boat_record_type,exists);
	MEM_INFO(boat_record_type,property);
	STRUCT_INFO(talk_save_type);
	MEM_INFO(talk_save_type,personality);
	MEM_INFO(talk_save_type,town_num);
	MEM_INFO(talk_save_type,str1);
	MEM_INFO(talk_save_type,str2);
	STRUCT_INFO(creature_data_type);
	MEM_INFO(creature_data_type,active);
	MEM_INFO(creature_data_type,attitude);
	MEM_INFO(creature_data_type,number);
	MEM_INFO(creature_data_type,m_loc);
	MEM_INFO(creature_data_type,m_d);
	MEM_INFO(creature_data_type,mobile);
	MEM_INFO(creature_data_type,summoned);
	MEM_INFO(creature_data_type,monst_start);
	STRUCT_INFO(creature_list_type);
	MEM_INFO(creature_list_type,dudes);
	MEM_INFO(creature_list_type,which_town);
	MEM_INFO(creature_list_type,hostile);
	STRUCT_INFO(outdoor_creature_type);
	MEM_INFO(outdoor_creature_type,exists);
	MEM_INFO(outdoor_creature_type,direction);
	MEM_INFO(outdoor_creature_type,what_monst);
	MEM_INFO(outdoor_creature_type,which_sector);
	MEM_INFO(outdoor_creature_type,m_loc);
	STRUCT_INFO(party_record_type);
	MEM_INFO(party_record_type,age);
	MEM_INFO(party_record_type,gold);
	MEM_INFO(party_record_type,food);
	MEM_INFO(party_record_type,stuff_done);
	MEM_INFO(party_record_type,item_taken);
	MEM_INFO(party_record_type,light_level);
	MEM_INFO(party_record_type,outdoor_corner);
	MEM_INFO(party_record_type,i_w_c);
	MEM_INFO(party_record_type,p_loc);
	MEM_INFO(party_record_type,loc_in_sec);
	MEM_INFO(party_record_type,boats);
	MEM_INFO(party_record_type,horses);
	MEM_INFO(party_record_type,creature_save);
	MEM_INFO(party_record_type,in_boat);
	MEM_INFO(party_record_type,in_horse);
	MEM_INFO(party_record_type,out_c);
	MEM_INFO(party_record_type,magic_store_items);
	MEM_INFO(party_record_type,imprisoned_monst);
	MEM_INFO(party_record_type,m_seen);
	MEM_INFO(party_record_type,journal_str);
	MEM_INFO(party_record_type,journal_day);
	MEM_INFO(party_record_type,special_notes_str);
	MEM_INFO(party_record_type,talk_save);
	MEM_INFO(party_record_type,direction);
	MEM_INFO(party_record_type,at_which_save_slot);
	MEM_INFO(party_record_type,alchemy);
	MEM_INFO(party_record_type,can_find_town);
	MEM_INFO(party_record_type,key_times);
	MEM_INFO(party_record_type,party_event_timers);
	MEM_INFO(party_record_type,global_or_town);
	MEM_INFO(party_record_type,node_to_call);
	MEM_INFO(party_record_type,spec_items);
	MEM_INFO(party_record_type,help_received);
	MEM_INFO(party_record_type,m_killed);
	MEM_INFO(party_record_type,total_m_killed);
	MEM_INFO(party_record_type,total_dam_done);
	MEM_INFO(party_record_type,total_xp_gained);
	MEM_INFO(party_record_type,total_dam_taken);
	MEM_INFO(party_record_type,scen_name);
	STRUCT_INFO(scenario_data_type);
	MEM_INFO(scenario_data_type,out_width);
	MEM_INFO(scenario_data_type,out_height);
	MEM_INFO(scenario_data_type,difficulty);
	MEM_INFO(scenario_data_type,intro_pic);
	MEM_INFO(scenario_data_type,default_ground);
	MEM_INFO(scenario_data_type,town_size);
	MEM_INFO(scenario_data_type,town_hidden);
	MEM_INFO(scenario_data_type,flag_a);
	MEM_INFO(scenario_data_type,intro_mess_pic);
	MEM_INFO(scenario_data_type,intro_mess_len);
	MEM_INFO(scenario_data_type,where_start);
	MEM_INFO(scenario_data_type,out_sec_start);
	MEM_INFO(scenario_data_type,out_start);
	MEM_INFO(scenario_data_type,which_town_start);
	MEM_INFO(scenario_data_type,flag_b);
	MEM_INFO(scenario_data_type,town_data_size);
	MEM_INFO(scenario_data_type,town_to_add_to);
	MEM_INFO(scenario_data_type,flag_to_add_to_town);
	MEM_INFO(scenario_data_type,flag_c);
	MEM_INFO(scenario_data_type,out_data_size);
	MEM_INFO(scenario_data_type,store_item_rects);
	MEM_INFO(scenario_data_type,store_item_towns);
	MEM_INFO(scenario_data_type,flag_e);
	MEM_INFO(scenario_data_type,special_items);
	MEM_INFO(scenario_data_type,special_item_special);
	MEM_INFO(scenario_data_type,rating);
	MEM_INFO(scenario_data_type,uses_custom_graphics);
	MEM_INFO(scenario_data_type,flag_f);
	MEM_INFO(scenario_data_type,scen_monsters);
	MEM_INFO(scenario_data_type,scen_boats);
	MEM_INFO(scenario_data_type,scen_horses);
	MEM_INFO(scenario_data_type,flag_g);
	MEM_INFO(scenario_data_type,ter_types);
	MEM_INFO(scenario_data_type,scenario_timer_times);
	MEM_INFO(scenario_data_type,scenario_timer_specs);
	MEM_INFO(scenario_data_type,flag_h);
	MEM_INFO(scenario_data_type,scen_specials);
	MEM_INFO(scenario_data_type,storage_shortcuts);
	MEM_INFO(scenario_data_type,flag_d);
	MEM_INFO(scenario_data_type,scen_str_len);
	MEM_INFO(scenario_data_type,flag_i);
	MEM_INFO(scenario_data_type,last_out_edited);
	MEM_INFO(scenario_data_type,last_town_edited);
	STRUCT_INFO(setup_save_type);
	MEM_INFO(setup_save_type,setup);
	STRUCT_INFO(pc_record_type);
	MEM_INFO(pc_record_type,main_status);
	MEM_INFO(pc_record_type,name);
	MEM_INFO(pc_record_type,skills);
	MEM_INFO(pc_record_type,max_health);
	MEM_INFO(pc_record_type,cur_health);
	MEM_INFO(pc_record_type,max_sp);
	MEM_INFO(pc_record_type,cur_sp);
	MEM_INFO(pc_record_type,experience);
	MEM_INFO(pc_record_type,skill_pts);
	MEM_INFO(pc_record_type,level);
	MEM_INFO(pc_record_type,status);
	MEM_INFO(pc_record_type,items);
	MEM_INFO(pc_record_type,equip);
	MEM_INFO(pc_record_type,priest_spells);
	MEM_INFO(pc_record_type,mage_spells);
	MEM_INFO(pc_record_type,which_graphic);
	MEM_INFO(pc_record_type,weap_poisoned);
	MEM_INFO(pc_record_type,advan);
	MEM_INFO(pc_record_type,traits);
	MEM_INFO(pc_record_type,race);
	MEM_INFO(pc_record_type,exp_adj);
	MEM_INFO(pc_record_type,direction);
	STRUCT_INFO(town_item_list);
	MEM_INFO(town_item_list,items);
	STRUCT_INFO(stored_town_maps_type);
	MEM_INFO(stored_town_maps_type,town_maps);
	STRUCT_INFO(stored_outdoor_maps_type);
	MEM_INFO(stored_outdoor_maps_type,outdoor_maps);
	STRUCT_INFO(stored_items_list_type);
	MEM_INFO(stored_items_list_type,items);
	STRUCT_INFO(current_town_type);
	MEM_INFO(current_town_type,town_num);
	MEM_INFO(current_town_type,difficulty);
	MEM_INFO(current_town_type,town);
	MEM_INFO(current_town_type,explored);
	MEM_INFO(current_town_type,hostile);
	MEM_INFO(current_town_type,monst);
	MEM_INFO(current_town_type,in_boat);
	MEM_INFO(current_town_type,p_loc);
	STRUCT_INFO(out_info_type);
	MEM_INFO(out_info_type,expl);
	
	
}

#ifdef _MSC_VER
#pragma warning(pop)
#endif
