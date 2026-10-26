MtMoon_B1F_MapScripts::
	.byte 0

MtMoon_B1F_EventScript_FloorSwitch0::
	lockall
	setvar VAR_TEMP_0, 1
	goto_if_eq VAR_TEMP_5, 1, MtMoon_B1F_EventScript_PuzzleNotSolved
	releaseall
	end

MtMoon_B1F_EventScript_FloorSwitch1::
	lockall
	setvar VAR_TEMP_1, 1
	goto_if_eq VAR_TEMP_5, 1, MtMoon_B1F_EventScript_PuzzleNotSolved
	releaseall
	end

MtMoon_B1F_EventScript_FloorSwitch2::
	lockall
	setvar VAR_TEMP_2, 1
	goto_if_eq VAR_TEMP_5, 1, MtMoon_B1F_EventScript_PuzzleNotSolved
	releaseall
	end

MtMoon_B1F_EventScript_FloorSwitch3::
	lockall
	setvar VAR_TEMP_3, 1
	goto_if_eq VAR_TEMP_5, 1, MtMoon_B1F_EventScript_PuzzleNotSolved
	releaseall
	end

MtMoon_B1F_EventScript_FloorSwitch4::
	lockall
	setvar VAR_TEMP_4, 1
	goto_if_eq VAR_TEMP_5, 1, MtMoon_B1F_EventScript_PuzzleNotSolved
	goto
	releaseall
	end

MtMoon_B1F_EventScript_FailedPuzzle::
	lockall
	setvar VAR_TEMP_5, 1
	goto_if_eq VAR_TEMP_5, 1, MtMoon_B1F_EventScript_PuzzleNotSolved
	releaseall
	end

MtMoon_B1F_EventScript_PuzzleNotSolved::
	releaseall
	end

MtMoon_B1F_EventScript_Puzzle::
	goto_if_eq VAR_TEMP_0, 1, MtMoon_B1F_EventScript_PuzzleNotSolved
	goto_if_eq VAR_TEMP_1, 1, MtMoon_B1F_EventScript_PuzzleNotSolved
	goto_if_eq VAR_TEMP_2, 1, MtMoon_B1F_EventScript_PuzzleNotSolved
	goto_if_eq VAR_TEMP_3, 1, MtMoon_B1F_EventScript_PuzzleNotSolved
	goto_if_eq VAR_TEMP_4, 1, MtMoon_B1F_EventScript_PuzzleNotSolved
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
	msgbox gText_DoorOpenedFarAway, MSGBOX_DEFAULT
	closemessage
	fadeinbgm 0
	releaseall
	end
