MtMoon_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtMoon_B1F_OnTransition
	.byte 0

MtMoon_B1F_OnTransition::
	goto_if_unset FLAG_OPEN_REGI_CAVES, MtMoon_B1F_EventScript_ResetVars
	setobjectxyperm LOCALID_MOON_BOLDER_0, 37, 25
	setobjectxyperm LOCALID_MOON_BOLDER_1, 39, 26
	setobjectxyperm LOCALID_MOON_BOLDER_2, 39, 28
	setobjectxyperm LOCALID_MOON_BOLDER_3, 35, 28
	setobjectxyperm LOCALID_MOON_BOLDER_4, 37, 29
	end

MtMoon_B1F_EventScript_ResetVars::
	clearflag FLAG_REGI_PUZZLE_0
	clearflag FLAG_REGI_PUZZLE_1
	clearflag FLAG_REGI_PUZZLE_2
	clearflag FLAG_REGI_PUZZLE_3
	clearflag FLAG_REGI_PUZZLE_FAIL
	end

MtMoon_B1F_EventScript_FloorSwitch::
	lockall
	playse SE_ICE_BREAK
	waitse
	goto_if_set FLAG_REGI_PUZZLE_FAIL, MtMoon_B1F_EventScript_PuzzleNotSolved
	goto_if_set FLAG_OPEN_REGI_CAVES, MtMoon_B1F_EventScript_PuzzleNotSolved
	goto_if_unset FLAG_REGI_PUZZLE_0, MtMoon_B1F_EventScript_PuzzleNotSolved0
	goto_if_unset FLAG_REGI_PUZZLE_1, MtMoon_B1F_EventScript_PuzzleNotSolved1
	goto_if_unset FLAG_REGI_PUZZLE_2, MtMoon_B1F_EventScript_PuzzleNotSolved2
	goto_if_unset FLAG_REGI_PUZZLE_3, MtMoon_B1F_EventScript_PuzzleNotSolved3
	goto MtMoon_B1F_EventScript_Puzzle
	releaseall
	end

MtMoon_B1F_EventScript_FailedPuzzle::
	lockall
	setflag FLAG_REGI_PUZZLE_FAIL
	goto_if_set FLAG_REGI_PUZZLE_FAIL, MtMoon_B1F_EventScript_PuzzleNotSolved
	goto MtMoon_B1F_EventScript_Puzzle
	releaseall
	end

MtMoon_B1F_EventScript_PuzzleNotSolved::
	releaseall
	end

MtMoon_B1F_EventScript_PuzzleNotSolved0::
	setflag FLAG_REGI_PUZZLE_0
	releaseall
	end

MtMoon_B1F_EventScript_PuzzleNotSolved1::
	setflag FLAG_REGI_PUZZLE_1
	releaseall
	end

MtMoon_B1F_EventScript_PuzzleNotSolved2::
	setflag FLAG_REGI_PUZZLE_2
	releaseall
	end

MtMoon_B1F_EventScript_PuzzleNotSolved3::
	setflag FLAG_REGI_PUZZLE_3
	releaseall
	end

MtMoon_B1F_EventScript_PrepReset::
	setvar VAR_TEMP_6, 1
	end

MtMoon_B1F_EventScript_CallReset::
	setvar VAR_TEMP_6, 0
	goto MtMoon_B1F_EventScript_ResetVars
	end

MtMoon_B1F_EventScript_Puzzle::
	setflag FLAG_OPEN_REGI_CAVES
	fadeoutbgm 0
	playse SE_TRUCK_MOVE
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeScreen
	delay 120
	delay 40
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeScreen
	delay 60
	playse SE_DOOR
	delay 40
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeScreen
	waitstate
	playse SE_DOOR
	delay 60
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeScreen
	waitstate
	playse SE_DOOR
	delay 60
	msgbox MtMoon_B1F_Text_DoorOpenedFarAway, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	setobjectxyperm LOCALID_MOON_BOLDER_0, 37, 25
	setobjectxyperm LOCALID_MOON_BOLDER_1, 39, 26
	setobjectxyperm LOCALID_MOON_BOLDER_2, 39, 28
	setobjectxyperm LOCALID_MOON_BOLDER_3, 35, 28
	setobjectxyperm LOCALID_MOON_BOLDER_4, 37, 29
	releaseall
	end
