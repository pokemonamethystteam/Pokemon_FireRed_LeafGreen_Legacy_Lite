NavelRock_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NavelRock_Summit_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, NavelRock_Summit_OnResume
	.byte 0

NavelRock_Summit_OnTransition::
	call_if_set FLAG_FOUGHT_HO_OH, NavelRock_Summit_EventScript_HideHoOh
	call_if_unset FLAG_FOUGHT_HO_OH, NavelRock_Summit_EventScript_TryShowHoOh
	end

NavelRock_Summit_EventScript_HideHoOh::
	setvar VAR_TEMP_1, 1
	setflag FLAG_HIDE_HO_OH
	return

NavelRock_Summit_EventScript_TryShowHoOh::
	setvar VAR_TEMP_1, 1
	goto_if_set FLAG_HO_OH_FLED, EventScript_Return
	setvar VAR_TEMP_1, 0
	clearflag FLAG_HIDE_HO_OH
	return

NavelRock_Summit_OnResume::
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, NavelRock_Summit_EventScript_TryRemoveHoOh
	end

NavelRock_Summit_EventScript_TryRemoveHoOh::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
	removeobject LOCALID_NAVEL_ROCK_HO_OH
	return

NavelRock_Summit_EventScript_HoOh::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lockall
	setvar VAR_TEMP_1, 1
	special SpawnCameraObject
	setvar VAR_0x8004, 3  @ Num loops
	setvar VAR_0x8005, 35 @ Delay
	special LoopWingFlapSound
	applymovement LOCALID_NAVEL_ROCK_HO_OH, Movement_HoOhAppear
	applymovement LOCALID_CAMERA, Movement_CameraPanUp
	waitmovement 0
	delay 50
	setweather 0
	doweather
	waitse
	playmoncry SPECIES_HO_OH, CRY_MODE_ENCOUNTER
	delay 30
	waitmoncry
	delay 60
	setvar VAR_0x8004, 3  @ Num loops
	setvar VAR_0x8005, 35 @ Delay
	special LoopWingFlapSound
	applymovement LOCALID_CAMERA, Movement_CameraPanDown
	applymovement LOCALID_NAVEL_ROCK_HO_OH, Movement_HoOhApproach
	waitmovement 0
	special RemoveCameraObject
	seteventmon SPECIES_HO_OH, 70
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	special StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	setvar VAR_LAST_TALKED, LOCALID_NAVEL_ROCK_HO_OH
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NavelRock_Summit_EventScript_DefeatedHoOh
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NavelRock_Summit_EventScript_RanFromHoOh
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NavelRock_Summit_EventScript_RanFromHoOh
	goto_if_unset FLAG_MET_HO_OH, NavelRock_Summit_EventScript_ReleaseRoamers
	releaseall
	end

NavelRock_Summit_EventScript_DefeatedHoOh::
	setflag FLAG_HO_OH_FLED
	setvar VAR_0x8004, SPECIES_HO_OH
	goto NavelRock_Summit_EventScript_MonFlewAway
	goto_if_unset FLAG_MET_HO_OH, NavelRock_Summit_EventScript_ReleaseRoamers
	releaseall
	end

NavelRock_Summit_EventScript_RanFromHoOh::
	setflag FLAG_HO_OH_FLED
	setvar VAR_0x8004, SPECIES_HO_OH
	goto NavelRock_Summit_EventScript_MonFlewAway
	goto_if_unset FLAG_MET_HO_OH, NavelRock_Summit_EventScript_ReleaseRoamers
	releaseall
	end

NavelRock_Summit_EventScript_MonFlewAway::
    fadescreen FADE_TO_BLACK
    removeobject LOCALID_NAVEL_ROCK_HO_OH
    fadescreen FADE_FROM_BLACK
    bufferspeciesname STR_VAR_1, VAR_0x8004
    msgbox Text_MonFlewAway, MSGBOX_AUTOCLOSE
	waitmessage
	goto_if_unset FLAG_MET_HO_OH, NavelRock_Summit_EventScript_ReleaseRoamers
	return

NavelRock_Summit_EventScript_ReleaseRoamers::
	special InitRoamer
	delay 40
	playmoncry SPECIES_RAIKOU, CRY_MODE_HIGH_PITCH
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 1  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeScreen
	waitstate
	waitmoncry
	delay 20
	playmoncry SPECIES_ENTEI, CRY_MODE_HIGH_PITCH
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 1  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeScreen
	waitstate
	waitmoncry
	delay 20
	playmoncry SPECIES_SUICUNE, CRY_MODE_HIGH_PITCH
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 0  @ horizontal pan
	setvar VAR_0x8006, 1  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeScreen
	waitstate
	waitmoncry
	clearflag FLAG_HIDE_LANCE_HOME
	setflag FLAG_MET_HO_OH
	releaseall
	end

Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

Movement_CameraPanDown:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Movement_HoOhApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	delay_16
	delay_16
	step_end

Movement_HoOhAppear:
	delay_16
	delay_16
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_down
	step_end
