SixIsland_OutcastIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_OutcastIsland_OnTransition
	.byte 0

SixIsland_OutcastIsland_OnTransition:
	random 10
	goto_if_eq VAR_RESULT, 0, SixIsland_OutcastIsland_AlteringCave0
	goto_if_eq VAR_RESULT, 1, SixIsland_OutcastIsland_AlteringCave1
	goto_if_eq VAR_RESULT, 2, SixIsland_OutcastIsland_AlteringCave2
	goto_if_eq VAR_RESULT, 3, SixIsland_OutcastIsland_AlteringCave3
	goto_if_eq VAR_RESULT, 4, SixIsland_OutcastIsland_AlteringCave4
	goto_if_eq VAR_RESULT, 5, SixIsland_OutcastIsland_AlteringCave5
	goto_if_eq VAR_RESULT, 6, SixIsland_OutcastIsland_AlteringCave6
	goto_if_eq VAR_RESULT, 7, SixIsland_OutcastIsland_AlteringCave7
	goto_if_eq VAR_RESULT, 8, SixIsland_OutcastIsland_AlteringCave8
	goto_if_eq VAR_RESULT, 9, SixIsland_OutcastIsland_AlteringCave9
	return

SixIsland_OutcastIsland_AlteringCave0::
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
	return

SixIsland_OutcastIsland_AlteringCave1::
	setvar VAR_ALTERING_CAVE_WILD_SET, 1
	return

SixIsland_OutcastIsland_AlteringCave2::
	setvar VAR_ALTERING_CAVE_WILD_SET, 2
	return

SixIsland_OutcastIsland_AlteringCave3::
	setvar VAR_ALTERING_CAVE_WILD_SET, 3
	return

SixIsland_OutcastIsland_AlteringCave4::
	setvar VAR_ALTERING_CAVE_WILD_SET, 4
	return

SixIsland_OutcastIsland_AlteringCave5::
	setvar VAR_ALTERING_CAVE_WILD_SET, 5
	return

SixIsland_OutcastIsland_AlteringCave6::
	setvar VAR_ALTERING_CAVE_WILD_SET, 6
	return

SixIsland_OutcastIsland_AlteringCave7::
	setvar VAR_ALTERING_CAVE_WILD_SET, 7
	return

SixIsland_OutcastIsland_AlteringCave8::
	setvar VAR_ALTERING_CAVE_WILD_SET, 8
	return
	
SixIsland_OutcastIsland_AlteringCave9::
	setvar VAR_ALTERING_CAVE_WILD_SET, 9
	return

SixIsland_OutcastIsland_EventScript_Rocket::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_46, SixIsland_OutcastIsland_Text_RocketIntro, SixIsland_OutcastIsland_Text_RocketDefeat
	msgbox SixIsland_OutcastIsland_Text_RocketPostBattle, MSGBOX_AUTOCLOSE
	end
