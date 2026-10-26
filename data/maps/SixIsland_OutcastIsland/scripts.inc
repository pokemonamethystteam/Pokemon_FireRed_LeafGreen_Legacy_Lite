SixIsland_OutcastIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_OutcastIsland_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, SixIsland_OutcastIsland_OnLoad
	.byte 0

SixIsland_OutcastIsland_OnTransition:
	random 10
	goto_if_eq VAR_RESULT, 0, SixIsland_OutcastIsland_EventScript_AlteringCave0
	goto_if_eq VAR_RESULT, 1, SixIsland_OutcastIsland_EventScript_AlteringCave1
	goto_if_eq VAR_RESULT, 2, SixIsland_OutcastIsland_EventScript_AlteringCave2
	goto_if_eq VAR_RESULT, 3, SixIsland_OutcastIsland_EventScript_AlteringCave3
	goto_if_eq VAR_RESULT, 4, SixIsland_OutcastIsland_EventScript_AlteringCave4
	goto_if_eq VAR_RESULT, 5, SixIsland_OutcastIsland_EventScript_AlteringCave5
	goto_if_eq VAR_RESULT, 6, SixIsland_OutcastIsland_EventScript_AlteringCave6
	goto_if_eq VAR_RESULT, 7, SixIsland_OutcastIsland_EventScript_AlteringCave7
	goto_if_eq VAR_RESULT, 8, SixIsland_OutcastIsland_EventScript_AlteringCave8
	goto_if_eq VAR_RESULT, 9, SixIsland_OutcastIsland_EventScript_AlteringCave9
	goto_if_eq VAR_REMOTE_LAB_STATE, 2, SixIsland_OutcastIsland_EventScript_SetUpRayquaza
	goto_if_unset FLAG_RAYQUAZA_FLEW_AWAY, SixIsland_OutcastIsland_EventScript_SetUpRayquazaRematch
	return

SixIsland_OutcastIsland_OnLoad::
	goto_if_eq VAR_REMOTE_LAB_STATE, 2, SixIsland_OutcastIsland_EventScript_SetUpRayquaza
	goto_if_unset FLAG_RAYQUAZA_FLEW_AWAY, SixIsland_OutcastIsland_EventScript_SetUpRayquazaRematch
	return

SixIsland_OutcastIsland_EventScript_AlteringCave0::
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
	return

SixIsland_OutcastIsland_EventScript_AlteringCave1::
	setvar VAR_ALTERING_CAVE_WILD_SET, 1
	return

SixIsland_OutcastIsland_EventScript_AlteringCave2::
	setvar VAR_ALTERING_CAVE_WILD_SET, 2
	return

SixIsland_OutcastIsland_EventScript_AlteringCave3::
	setvar VAR_ALTERING_CAVE_WILD_SET, 3
	return

SixIsland_OutcastIsland_EventScript_AlteringCave4::
	setvar VAR_ALTERING_CAVE_WILD_SET, 4
	return

SixIsland_OutcastIsland_EventScript_AlteringCave5::
	setvar VAR_ALTERING_CAVE_WILD_SET, 5
	return

SixIsland_OutcastIsland_EventScript_AlteringCave6::
	setvar VAR_ALTERING_CAVE_WILD_SET, 6
	return

SixIsland_OutcastIsland_EventScript_AlteringCave7::
	setvar VAR_ALTERING_CAVE_WILD_SET, 7
	return

SixIsland_OutcastIsland_EventScript_AlteringCave8::
	setvar VAR_ALTERING_CAVE_WILD_SET, 8
	return
	
SixIsland_OutcastIsland_EventScript_AlteringCave9::
	setvar VAR_ALTERING_CAVE_WILD_SET, 9
	return

SixIsland_OutcastIsland_EventScript_Rocket::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_46, SixIsland_OutcastIsland_Text_RocketIntro, SixIsland_OutcastIsland_Text_RocketDefeat
	msgbox SixIsland_OutcastIsland_Text_RocketPostBattle, MSGBOX_AUTOCLOSE
	end

SixIsland_OutcastIsland_EventScript_SetUpRayquaza::
	Setobjectxyperm LOCAL_ID_WEATHER_GUY_OUTCAST_ISLAND, 7, 16
	end

SixIsland_OutcastIsland_EventScript_SetUpRayquazaRematch::
	goto_if_eq VAR_REMOTE_LAB_STATE, 1, SixIsland_OutcastIsland_EventScript_End
	goto_if_eq VAR_REMOTE_LAB_STATE, 0, SixIsland_OutcastIsland_EventScript_End
	goto_if_set FLAG_CAUGHT_RAYQUAZA, SixIsland_OutcastIsland_EventScript_End
	setweather WEATHER_SHADE
	doweather
	end

SixIsland_OutcastIsland_EventScript_End::
	end

SixIsland_OutcastIsland_EventScript_TestMusic::
	goto_if_eq VAR_REMOTE_LAB_STATE, 2, SixIsland_OutcastIsland_EventScript_SetMusic
	setvar VAR_TEMP_A, 1
	end

SixIsland_OutcastIsland_EventScript_TestResetMusic::
	goto_if_eq VAR_REMOTE_LAB_STATE, 2, SixIsland_OutcastIsland_EventScript_ReSetMusic
	setvar VAR_TEMP_A, 0
	end

SixIsland_OutcastIsland_EventScript_SetMusic::
	fadenewbgm MUS_SEVII_CAVE
	setvar VAR_TEMP_A, 1
	end

SixIsland_OutcastIsland_EventScript_ReSetMusic::
	fadedefaultbgm
	setvar VAR_TEMP_A, 0
	end

SixIsland_OutcastIsland_EventScript_RayquazaScene::
	lock
	setvar VAR_TEMP_B, 1
	applymovement LOCALID_PLAYER, SixIsland_OutcastIsland_Movement_RayquazaScene1
	waitmovement 0
	applymovement LOCAL_ID_WEATHER_GUY_OUTCAST_ISLAND, Common_Movement_FaceLeft
	waitmovement 0
	msgbox SixIsland_OutcastIsland_Text_Rayquaza1, MSGBOX_NPC
	closemessage
	delay 20
	applymovement LOCAL_ID_WEATHER_GUY_OUTCAST_ISLAND, SixIsland_OutcastIsland_Movement_RayquazaScene2
	waitmovement 0
	msgbox SixIsland_OutcastIsland_Text_Rayquaza2, MSGBOX_NPC
	closemessage
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeScreen
	waitstate
	waitse
	playbgm MUS_NONE, 0
	applymovement LOCALID_PLAYER, SixIsland_OutcastIsland_Movement_RayquazaSurprise
	applymovement LOCAL_ID_SCARRED_FISHERMAN, SixIsland_OutcastIsland_Movement_RayquazaSurprise
	applymovement LOCAL_ID_WEATHER_GUY_OUTCAST_ISLAND, SixIsland_OutcastIsland_Movement_RayquazaSurprise
	waitmovement 0
	delay 40
	applymovement LOCAL_ID_WEATHER_GUY_OUTCAST_ISLAND, SixIsland_OutcastIsland_Movement_RayquazaScene3Scientist
	applymovement LOCALID_PLAYER, SixIsland_OutcastIsland_Movement_RayquazaScene3Player
	waitmovement 0
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	playse SE_M_RAZOR_WIND
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeScreen
	applymovement LOCAL_ID_RAYQUAZA, SixIsland_OutcastIsland_Movement_RayquazaFlyIn
	waitmovement 0
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeScreen
	waitstate
	waitmoncry
	delay 20
	seteventmon SPECIES_RAYQUAZA, 70
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SixIsland_OutcastIsland_EventScript_DefeatedRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SixIsland_OutcastIsland_EventScript_RanFromRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SixIsland_OutcastIsland_EventScript_RanFromRayquaza
    fadescreen FADE_TO_BLACK
    removeobject LOCAL_ID_RAYQUAZA
    fadescreen FADE_FROM_BLACK
	setweather WEATHER_SUNNY
	doweather
	waitse
	setflag FLAG_CAUGHT_RAYQUAZA
	goto SixIsland_OutcastIsland_EventScript_RayquazaEnd
SixIsland_OutcastIsland_EventScript_RayquazaEnd::
	setvar VAR_REMOTE_LAB_STATE, 3
	clearflag FLAG_HIDE_WEATHER_GUY
	applymovement LOCALID_PLAYER, SixIsland_OutcastIsland_Movement_RayquazaScene4PlayerToScientist
	waitmovement 0
	applymovement LOCAL_ID_WEATHER_GUY_OUTCAST_ISLAND, Common_Movement_FaceLeft
	waitmovement 0
	msgbox SixIsland_OutcastIsland_Text_RayquazaLeave, MSGBOX_NPC
	applymovement LOCAL_ID_WEATHER_GUY_OUTCAST_ISLAND, SixIsland_OutcastIsland_Movement_RayquazaScene4ScientistLeave
	waitmovement 0
	removeobject LOCAL_ID_WEATHER_GUY_OUTCAST_ISLAND
	Setobjectxyperm LOCAL_ID_WEATHER_GUY_OUTCAST_ISLAND, 0, 1
	release
	end

SixIsland_OutcastIsland_EventScript_DefeatedRayquaza::
	setflag FLAG_RAYQUAZA_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_RAYQUAZA
	goto SixIsland_OutcastIsland_EventScript_MonFlewAway
	end

SixIsland_OutcastIsland_EventScript_RanFromRayquaza::
	setflag FLAG_RAYQUAZA_FLEW_AWAY
	setvar VAR_0x8004, SPECIES_RAYQUAZA
	goto SixIsland_OutcastIsland_EventScript_MonFlewAway
	release
	end

SixIsland_OutcastIsland_EventScript_MonFlewAway::
    fadescreen FADE_TO_BLACK
    removeobject LOCAL_ID_RAYQUAZA
    fadescreen FADE_FROM_BLACK
	setweather WEATHER_SUNNY
	doweather
	waitse
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_MonFlewAway, MSGBOX_AUTOCLOSE
	goto_if_eq VAR_REMOTE_LAB_STATE, 2, SixIsland_OutcastIsland_EventScript_RayquazaEnd
    release
    end

SixIsland_OutcastIsland_EventScript_TextRayquazaRematch::
	setvar VAR_TEMP_B, 1
	goto_if_eq VAR_REMOTE_LAB_STATE, 1, SixIsland_OutcastIsland_EventScript_End
	goto_if_eq VAR_REMOTE_LAB_STATE, 0, SixIsland_OutcastIsland_EventScript_End
	goto_if_set FLAG_CAUGHT_RAYQUAZA, SixIsland_OutcastIsland_EventScript_End
	goto_if_unset FLAG_RAYQUAZA_FLEW_AWAY, SixIsland_OutcastIsland_EventScript_RayquazaRematch
	end

SixIsland_OutcastIsland_EventScript_RayquazaRematch::
	lock
	setvar VAR_TEMP_B, 1
	delay 40
	playbgm MUS_ENCOUNTER_GYM_LEADER, 0
	playse SE_M_RAZOR_WIND
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeScreen
	applymovement LOCAL_ID_RAYQUAZA, SixIsland_OutcastIsland_Movement_RayquazaFlyIn
	waitmovement 0
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeScreen
	waitstate
	waitmoncry
	delay 20
	seteventmon SPECIES_RAYQUAZA, 70
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SixIsland_OutcastIsland_EventScript_DefeatedRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SixIsland_OutcastIsland_EventScript_RanFromRayquaza
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SixIsland_OutcastIsland_EventScript_RanFromRayquaza
    fadescreen FADE_TO_BLACK
    removeobject LOCAL_ID_RAYQUAZA
    fadescreen FADE_FROM_BLACK
	setweather WEATHER_SUNNY
	doweather
	waitse
	setflag FLAG_CAUGHT_RAYQUAZA
	release
	end

SixIsland_OutcastIsland_Movement_RayquazaScene1:
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

SixIsland_OutcastIsland_Movement_RayquazaScene2:
	walk_right
	delay_16
	delay_16
	delay_16
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	walk_left
	step_end

SixIsland_OutcastIsland_Movement_RayquazaSurprise:
	face_up
	emote_exclamation_mark
	step_end

SixIsland_OutcastIsland_Movement_RayquazaScene3Player:
	walk_fast_left
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

SixIsland_OutcastIsland_Movement_RayquazaScene3Scientist:
	walk_fast_up
	step_end

SixIsland_OutcastIsland_Movement_RayquazaScene4PlayerToScientist:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_right
	walk_right
	delay_16
	step_end

SixIsland_OutcastIsland_Movement_RayquazaScene4ScientistLeave:
	walk_slow_down
	walk_slow_left
	walk_slow_left
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end

SixIsland_OutcastIsland_Movement_RayquazaFlyIn:
	slide_down
	slide_down
	glide_down
	glide_down
	glide_down
	walk_in_place_slow_right
	walk_in_place_slow_left
	delay_16
	walk_in_place_slow_right
	walk_in_place_up
	step_end
