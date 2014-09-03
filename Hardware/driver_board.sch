EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:TLC5940
LIBS:driver_board-cache
EELAYER 24 0
EELAYER END
$Descr A0 46811 33110
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	6550 5450 6550 5400
Wire Wire Line
	8350 5400 8600 5400
$Comp
L CONN_4X2 P1
U 1 1 53A8FE24
P 4850 4450
F 0 "P1" H 4850 4700 50  0000 C CNN
F 1 "CONN_4X2" V 4850 4450 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 4850 4450 60  0001 C CNN
F 3 "" H 4850 4450 60  0000 C CNN
	1    4850 4450
	-1   0    0    -1  
$EndComp
Text Label 4450 4300 2    60   ~ 0
ROA1
Text Label 6550 4300 2    60   ~ 0
ROA1
Text Label 5250 4300 0    60   ~ 0
ROA2
Text Label 4450 4400 2    60   ~ 0
ROA3
Text Label 5250 4400 0    60   ~ 0
ROA4
Text Label 4450 4500 2    60   ~ 0
ROA5
Text Label 5250 4500 0    60   ~ 0
ROA6
Text Label 4450 4600 2    60   ~ 0
ROA7
Text Label 5250 4600 0    60   ~ 0
ROA8
Text Label 6550 4400 2    60   ~ 0
ROA2
Text Label 6550 4500 2    60   ~ 0
ROA3
Text Label 6550 4600 2    60   ~ 0
ROA4
Text Label 6550 4700 2    60   ~ 0
ROA5
Text Label 6550 4800 2    60   ~ 0
ROA6
Text Label 6550 4900 2    60   ~ 0
ROA7
Text Label 6550 5000 2    60   ~ 0
ROA8
$Comp
L TLC590 U1
U 1 1 53A8E425
P 7550 4750
F 0 "U1" H 7750 3450 60  0000 C CNN
F 1 "TLC590" H 7450 3450 60  0000 C CNN
F 2 "TLC5940:SSOP-28H" H 7550 4750 60  0001 C CNN
F 3 "" H 7550 4750 60  0000 C CNN
	1    7550 4750
	1    0    0    -1  
$EndComp
$Comp
L CONN_4X2 P5
U 1 1 53A8E719
P 4850 5050
F 0 "P5" H 4850 5300 50  0000 C CNN
F 1 "CONN_4X2" V 4850 5050 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 4850 5050 60  0001 C CNN
F 3 "" H 4850 5050 60  0000 C CNN
	1    4850 5050
	1    0    0    -1  
$EndComp
Text Label 4450 4900 2    60   ~ 0
ROA9
Text Label 5250 4900 0    60   ~ 0
ROA10
Text Label 4450 5000 2    60   ~ 0
ROA11
Text Label 5250 5000 0    60   ~ 0
ROA12
Text Label 4450 5100 2    60   ~ 0
ROA13
Text Label 5250 5100 0    60   ~ 0
ROA14
Text Label 4450 5200 2    60   ~ 0
ROA15
Text Label 5250 5200 0    60   ~ 0
ROA16
Text Label 6550 5100 2    60   ~ 0
ROA9
Text Label 6550 5200 2    60   ~ 0
ROA10
Text Label 6550 5300 2    60   ~ 0
ROA11
Text Label 6550 5400 2    60   ~ 0
ROA12
Text Label 6550 5500 2    60   ~ 0
ROA13
Text Label 6550 5600 2    60   ~ 0
ROA14
Text Label 6550 5700 2    60   ~ 0
ROA15
Text Label 6550 5800 2    60   ~ 0
ROA16
Text Label 7350 3950 1    60   ~ 0
vprg
Text Label 7550 3950 1    60   ~ 0
sclk
Text Label 7650 3950 1    60   ~ 0
xlat
Text Label 7750 3950 1    60   ~ 0
blank
Text Label 7850 3950 1    60   ~ 0
gnd
Text Label 8350 5300 0    60   ~ 0
vcc
Text Label 8350 5500 0    60   ~ 0
dcprg
Text Label 8350 5600 0    60   ~ 0
gsclk
Text Label 8350 5800 0    60   ~ 0
xerr
$Comp
L R R1
U 1 1 53A8EAAB
P 8850 5400
F 0 "R1" V 8930 5400 40  0000 C CNN
F 1 "R" V 8857 5401 40  0000 C CNN
F 2 "Resistors_SMD:Resistor_SMD0805_HandSoldering" V 8780 5400 30  0001 C CNN
F 3 "" H 8850 5400 30  0000 C CNN
	1    8850 5400
	0    1    1    0   
$EndComp
Wire Wire Line
	9100 5400 9250 5400
$Comp
L GND #PWR01
U 1 1 53A8EB9E
P 9250 5400
F 0 "#PWR01" H 9250 5400 30  0001 C CNN
F 1 "GND" H 9250 5330 30  0001 C CNN
F 2 "" H 9250 5400 60  0000 C CNN
F 3 "" H 9250 5400 60  0000 C CNN
	1    9250 5400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11250 5450 11250 5400
Wire Wire Line
	13050 5400 13300 5400
$Comp
L CONN_4X2 P2
U 1 1 53A8F43E
P 9550 4450
F 0 "P2" H 9550 4700 50  0000 C CNN
F 1 "CONN_4X2" V 9550 4450 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 9550 4450 60  0001 C CNN
F 3 "" H 9550 4450 60  0000 C CNN
	1    9550 4450
	-1   0    0    -1  
$EndComp
Text Label 9150 4300 2    60   ~ 0
ROB1
Text Label 11250 4300 2    60   ~ 0
ROB1
Text Label 9950 4300 0    60   ~ 0
ROB2
Text Label 9150 4400 2    60   ~ 0
ROB3
Text Label 9950 4400 0    60   ~ 0
ROB4
Text Label 9150 4500 2    60   ~ 0
ROB5
Text Label 9950 4500 0    60   ~ 0
ROB6
Text Label 9150 4600 2    60   ~ 0
ROB7
Text Label 9950 4600 0    60   ~ 0
ROB8
Text Label 11250 4400 2    60   ~ 0
ROB2
Text Label 11250 4500 2    60   ~ 0
ROB3
Text Label 11250 4600 2    60   ~ 0
ROB4
Text Label 11250 4700 2    60   ~ 0
ROB5
Text Label 11250 4800 2    60   ~ 0
ROB6
Text Label 11250 4900 2    60   ~ 0
ROB7
Text Label 11250 5000 2    60   ~ 0
ROB8
$Comp
L TLC590 U2
U 1 1 53A8F454
P 12250 4750
F 0 "U2" H 12450 3450 60  0000 C CNN
F 1 "TLC590" H 12150 3450 60  0000 C CNN
F 2 "TLC5940:SSOP-28H" H 12250 4750 60  0001 C CNN
F 3 "" H 12250 4750 60  0000 C CNN
	1    12250 4750
	1    0    0    -1  
$EndComp
$Comp
L CONN_4X2 P6
U 1 1 53A8F45A
P 9550 5050
F 0 "P6" H 9550 5300 50  0000 C CNN
F 1 "CONN_4X2" V 9550 5050 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 9550 5050 60  0001 C CNN
F 3 "" H 9550 5050 60  0000 C CNN
	1    9550 5050
	1    0    0    -1  
$EndComp
Text Label 9150 4900 2    60   ~ 0
ROB9
Text Label 9950 4900 0    60   ~ 0
ROB10
Text Label 9150 5000 2    60   ~ 0
ROB11
Text Label 9950 5000 0    60   ~ 0
ROB12
Text Label 9150 5100 2    60   ~ 0
ROB13
Text Label 9950 5100 0    60   ~ 0
ROB14
Text Label 9150 5200 2    60   ~ 0
ROB15
Text Label 9950 5200 0    60   ~ 0
ROB16
Text Label 11250 5100 2    60   ~ 0
ROB9
Text Label 11250 5200 2    60   ~ 0
ROB10
Text Label 11250 5300 2    60   ~ 0
ROB11
Text Label 11250 5400 2    60   ~ 0
ROB12
Text Label 11250 5500 2    60   ~ 0
ROB13
Text Label 11250 5600 2    60   ~ 0
ROB14
Text Label 11250 5700 2    60   ~ 0
ROB15
Text Label 11250 5800 2    60   ~ 0
ROB16
Text Label 12050 3950 1    60   ~ 0
vprg
Text Label 12250 3950 1    60   ~ 0
sclk
Text Label 12350 3950 1    60   ~ 0
xlat
Text Label 12450 3950 1    60   ~ 0
blank
Text Label 12550 3950 1    60   ~ 0
gnd
Text Label 13050 5300 0    60   ~ 0
vcc
Text Label 13050 5500 0    60   ~ 0
dcprg
Text Label 13050 5600 0    60   ~ 0
gsclk
Text Label 13050 5800 0    60   ~ 0
xerr
$Comp
L R R2
U 1 1 53A8F479
P 13550 5400
F 0 "R2" V 13630 5400 40  0000 C CNN
F 1 "R" V 13557 5401 40  0000 C CNN
F 2 "Resistors_SMD:Resistor_SMD0805_HandSoldering" V 13480 5400 30  0001 C CNN
F 3 "" H 13550 5400 30  0000 C CNN
	1    13550 5400
	0    1    1    0   
$EndComp
Wire Wire Line
	15950 5450 15950 5400
Wire Wire Line
	17750 5400 18000 5400
$Comp
L CONN_4X2 P3
U 1 1 53A8FD59
P 14250 4450
F 0 "P3" H 14250 4700 50  0000 C CNN
F 1 "CONN_4X2" V 14250 4450 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 14250 4450 60  0001 C CNN
F 3 "" H 14250 4450 60  0000 C CNN
	1    14250 4450
	-1   0    0    -1  
$EndComp
Text Label 13850 4300 2    60   ~ 0
ROC1
Text Label 15950 4300 2    60   ~ 0
ROC1
Text Label 14650 4300 0    60   ~ 0
ROC2
Text Label 13850 4400 2    60   ~ 0
ROC3
Text Label 14650 4400 0    60   ~ 0
ROC4
Text Label 13850 4500 2    60   ~ 0
ROC5
Text Label 14650 4500 0    60   ~ 0
ROC6
Text Label 13850 4600 2    60   ~ 0
ROC7
Text Label 14650 4600 0    60   ~ 0
ROC8
Text Label 15950 4400 2    60   ~ 0
ROC2
Text Label 15950 4500 2    60   ~ 0
ROC3
Text Label 15950 4600 2    60   ~ 0
ROC4
Text Label 15950 4700 2    60   ~ 0
ROC5
Text Label 15950 4800 2    60   ~ 0
ROC6
Text Label 15950 4900 2    60   ~ 0
ROC7
Text Label 15950 5000 2    60   ~ 0
ROC8
$Comp
L TLC590 U3
U 1 1 53A8FD6F
P 16950 4750
F 0 "U3" H 17150 3450 60  0000 C CNN
F 1 "TLC590" H 16850 3450 60  0000 C CNN
F 2 "TLC5940:SSOP-28H" H 16950 4750 60  0001 C CNN
F 3 "" H 16950 4750 60  0000 C CNN
	1    16950 4750
	1    0    0    -1  
$EndComp
$Comp
L CONN_4X2 P7
U 1 1 53A8FD75
P 14250 5050
F 0 "P7" H 14250 5300 50  0000 C CNN
F 1 "CONN_4X2" V 14250 5050 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 14250 5050 60  0001 C CNN
F 3 "" H 14250 5050 60  0000 C CNN
	1    14250 5050
	1    0    0    -1  
$EndComp
Text Label 13850 4900 2    60   ~ 0
ROC9
Text Label 14650 4900 0    60   ~ 0
ROC10
Text Label 13850 5000 2    60   ~ 0
ROC11
Text Label 14650 5000 0    60   ~ 0
ROC12
Text Label 13850 5100 2    60   ~ 0
ROC13
Text Label 14650 5100 0    60   ~ 0
ROC14
Text Label 13850 5200 2    60   ~ 0
ROC15
Text Label 14650 5200 0    60   ~ 0
ROC16
Text Label 15950 5100 2    60   ~ 0
ROC9
Text Label 15950 5200 2    60   ~ 0
ROC10
Text Label 15950 5300 2    60   ~ 0
ROC11
Text Label 15950 5400 2    60   ~ 0
ROC12
Text Label 15950 5500 2    60   ~ 0
ROC13
Text Label 15950 5600 2    60   ~ 0
ROC14
Text Label 15950 5700 2    60   ~ 0
ROC15
Text Label 15950 5800 2    60   ~ 0
ROC16
Text Label 16750 3950 1    60   ~ 0
vprg
Text Label 16950 3950 1    60   ~ 0
sclk
Text Label 17050 3950 1    60   ~ 0
xlat
Text Label 17150 3950 1    60   ~ 0
blank
Text Label 17250 3950 1    60   ~ 0
gnd
Text Label 17750 5300 0    60   ~ 0
vcc
Text Label 17750 5500 0    60   ~ 0
dcprg
Text Label 17750 5600 0    60   ~ 0
gsclk
Text Label 17750 5800 0    60   ~ 0
xerr
$Comp
L R R3
U 1 1 53A8FD94
P 18250 5400
F 0 "R3" V 18330 5400 40  0000 C CNN
F 1 "R" V 18257 5401 40  0000 C CNN
F 2 "Resistors_SMD:Resistor_SMD0805_HandSoldering" V 18180 5400 30  0001 C CNN
F 3 "" H 18250 5400 30  0000 C CNN
	1    18250 5400
	0    1    1    0   
$EndComp
Wire Wire Line
	18500 5400 18650 5400
$Comp
L GND #PWR02
U 1 1 53A8FD9B
P 18650 5400
F 0 "#PWR02" H 18650 5400 30  0001 C CNN
F 1 "GND" H 18650 5330 30  0001 C CNN
F 2 "" H 18650 5400 60  0000 C CNN
F 3 "" H 18650 5400 60  0000 C CNN
	1    18650 5400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	20650 5450 20650 5400
Wire Wire Line
	22450 5400 22700 5400
$Comp
L CONN_4X2 P4
U 1 1 53A8FDA3
P 18950 4450
F 0 "P4" H 18950 4700 50  0000 C CNN
F 1 "CONN_4X2" V 18950 4450 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 18950 4450 60  0001 C CNN
F 3 "" H 18950 4450 60  0000 C CNN
	1    18950 4450
	-1   0    0    -1  
$EndComp
Text Label 18550 4300 2    60   ~ 0
ROD1
Text Label 20650 4300 2    60   ~ 0
ROD1
Text Label 19350 4300 0    60   ~ 0
ROD2
Text Label 18550 4400 2    60   ~ 0
ROD3
Text Label 19350 4400 0    60   ~ 0
ROD4
Text Label 18550 4500 2    60   ~ 0
ROD5
Text Label 19350 4500 0    60   ~ 0
ROD6
Text Label 18550 4600 2    60   ~ 0
ROD7
Text Label 19350 4600 0    60   ~ 0
ROD8
Text Label 20650 4400 2    60   ~ 0
ROD2
Text Label 20650 4500 2    60   ~ 0
ROD3
Text Label 20650 4600 2    60   ~ 0
ROD4
Text Label 20650 4700 2    60   ~ 0
ROD5
Text Label 20650 4800 2    60   ~ 0
ROD6
Text Label 20650 4900 2    60   ~ 0
ROD7
Text Label 20650 5000 2    60   ~ 0
ROD8
$Comp
L TLC590 U4
U 1 1 53A8FDB9
P 21650 4750
F 0 "U4" H 21850 3450 60  0000 C CNN
F 1 "TLC590" H 21550 3450 60  0000 C CNN
F 2 "TLC5940:SSOP-28H" H 21650 4750 60  0001 C CNN
F 3 "" H 21650 4750 60  0000 C CNN
	1    21650 4750
	1    0    0    -1  
$EndComp
$Comp
L CONN_4X2 P8
U 1 1 53A8FDBF
P 18950 5050
F 0 "P8" H 18950 5300 50  0000 C CNN
F 1 "CONN_4X2" V 18950 5050 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 18950 5050 60  0001 C CNN
F 3 "" H 18950 5050 60  0000 C CNN
	1    18950 5050
	1    0    0    -1  
$EndComp
Text Label 18550 4900 2    60   ~ 0
ROD9
Text Label 19350 4900 0    60   ~ 0
ROD10
Text Label 18550 5000 2    60   ~ 0
ROD11
Text Label 19350 5000 0    60   ~ 0
ROD12
Text Label 18550 5100 2    60   ~ 0
ROD13
Text Label 19350 5100 0    60   ~ 0
ROD14
Text Label 18550 5200 2    60   ~ 0
ROD15
Text Label 19350 5200 0    60   ~ 0
ROD16
Text Label 20650 5100 2    60   ~ 0
ROD9
Text Label 20650 5200 2    60   ~ 0
ROD10
Text Label 20650 5300 2    60   ~ 0
ROD11
Text Label 20650 5400 2    60   ~ 0
ROD12
Text Label 20650 5500 2    60   ~ 0
ROD13
Text Label 20650 5600 2    60   ~ 0
ROD14
Text Label 20650 5700 2    60   ~ 0
ROD15
Text Label 20650 5800 2    60   ~ 0
ROD16
Text Label 21450 3950 1    60   ~ 0
vprg
Text Label 21650 3950 1    60   ~ 0
sclk
Text Label 21750 3950 1    60   ~ 0
xlat
Text Label 21850 3950 1    60   ~ 0
blank
Text Label 21950 3950 1    60   ~ 0
gnd
Text Label 22450 5300 0    60   ~ 0
vcc
Text Label 22450 5500 0    60   ~ 0
dcprg
Text Label 22450 5600 0    60   ~ 0
gsclk
Text Label 22450 5800 0    60   ~ 0
xerr
$Comp
L R R4
U 1 1 53A8FDDE
P 22950 5400
F 0 "R4" V 23030 5400 40  0000 C CNN
F 1 "R" V 22957 5401 40  0000 C CNN
F 2 "Resistors_SMD:Resistor_SMD0805_HandSoldering" V 22880 5400 30  0001 C CNN
F 3 "" H 22950 5400 30  0000 C CNN
	1    22950 5400
	0    1    1    0   
$EndComp
Wire Wire Line
	6550 8000 6550 7950
Wire Wire Line
	8350 7950 8600 7950
$Comp
L CONN_4X2 P9
U 1 1 53A908B6
P 4850 7000
F 0 "P9" H 4850 7250 50  0000 C CNN
F 1 "CONN_4X2" V 4850 7000 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 4850 7000 60  0001 C CNN
F 3 "" H 4850 7000 60  0000 C CNN
	1    4850 7000
	-1   0    0    -1  
$EndComp
Text Label 4450 6850 2    60   ~ 0
GOA1
Text Label 6550 6850 2    60   ~ 0
GOA1
Text Label 5250 6850 0    60   ~ 0
GOA2
Text Label 4450 6950 2    60   ~ 0
GOA3
Text Label 5250 6950 0    60   ~ 0
GOA4
Text Label 4450 7050 2    60   ~ 0
GOA5
Text Label 5250 7050 0    60   ~ 0
GOA6
Text Label 4450 7150 2    60   ~ 0
GOA7
Text Label 5250 7150 0    60   ~ 0
GOA8
Text Label 6550 6950 2    60   ~ 0
GOA2
Text Label 6550 7050 2    60   ~ 0
GOA3
Text Label 6550 7150 2    60   ~ 0
GOA4
Text Label 6550 7250 2    60   ~ 0
GOA5
Text Label 6550 7350 2    60   ~ 0
GOA6
Text Label 6550 7450 2    60   ~ 0
GOA7
Text Label 6550 7550 2    60   ~ 0
GOA8
$Comp
L TLC590 U5
U 1 1 53A908CC
P 7550 7300
F 0 "U5" H 7750 6000 60  0000 C CNN
F 1 "TLC590" H 7450 6000 60  0000 C CNN
F 2 "TLC5940:SSOP-28H" H 7550 7300 60  0001 C CNN
F 3 "" H 7550 7300 60  0000 C CNN
	1    7550 7300
	1    0    0    -1  
$EndComp
$Comp
L CONN_4X2 P13
U 1 1 53A908D2
P 4850 7600
F 0 "P13" H 4850 7850 50  0000 C CNN
F 1 "CONN_4X2" V 4850 7600 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 4850 7600 60  0001 C CNN
F 3 "" H 4850 7600 60  0000 C CNN
	1    4850 7600
	1    0    0    -1  
$EndComp
Text Label 4450 7450 2    60   ~ 0
GOA9
Text Label 5250 7450 0    60   ~ 0
GOA10
Text Label 4450 7550 2    60   ~ 0
GOA11
Text Label 5250 7550 0    60   ~ 0
GOA12
Text Label 4450 7650 2    60   ~ 0
GOA13
Text Label 5250 7650 0    60   ~ 0
GOA14
Text Label 4450 7750 2    60   ~ 0
GOA15
Text Label 5250 7750 0    60   ~ 0
GOA16
Text Label 6550 7650 2    60   ~ 0
GOA9
Text Label 6550 7750 2    60   ~ 0
GOA10
Text Label 6550 7850 2    60   ~ 0
GOA11
Text Label 6550 7950 2    60   ~ 0
GOA12
Text Label 6550 8050 2    60   ~ 0
GOA13
Text Label 6550 8150 2    60   ~ 0
GOA14
Text Label 6550 8250 2    60   ~ 0
GOA15
Text Label 6550 8350 2    60   ~ 0
GOA16
Text Label 7350 6500 1    60   ~ 0
vprg
Text Label 7550 6500 1    60   ~ 0
sclk
Text Label 7650 6500 1    60   ~ 0
xlat
Text Label 7750 6500 1    60   ~ 0
blank
Text Label 7850 6500 1    60   ~ 0
gnd
Text Label 8350 7850 0    60   ~ 0
vcc
Text Label 8350 8050 0    60   ~ 0
dcprg
Text Label 8350 8150 0    60   ~ 0
gsclk
Text Label 8350 8350 0    60   ~ 0
xerr
$Comp
L R R5
U 1 1 53A908F1
P 8850 7950
F 0 "R5" V 8930 7950 40  0000 C CNN
F 1 "R" V 8857 7951 40  0000 C CNN
F 2 "Resistors_SMD:Resistor_SMD0805_HandSoldering" V 8780 7950 30  0001 C CNN
F 3 "" H 8850 7950 30  0000 C CNN
	1    8850 7950
	0    1    1    0   
$EndComp
Wire Wire Line
	9100 7950 9250 7950
$Comp
L GND #PWR03
U 1 1 53A908F8
P 9250 7950
F 0 "#PWR03" H 9250 7950 30  0001 C CNN
F 1 "GND" H 9250 7880 30  0001 C CNN
F 2 "" H 9250 7950 60  0000 C CNN
F 3 "" H 9250 7950 60  0000 C CNN
	1    9250 7950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11250 8000 11250 7950
Wire Wire Line
	13050 7950 13300 7950
$Comp
L CONN_4X2 P10
U 1 1 53A90900
P 9550 7000
F 0 "P10" H 9550 7250 50  0000 C CNN
F 1 "CONN_4X2" V 9550 7000 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 9550 7000 60  0001 C CNN
F 3 "" H 9550 7000 60  0000 C CNN
	1    9550 7000
	-1   0    0    -1  
$EndComp
Text Label 9150 6850 2    60   ~ 0
GOB1
Text Label 11250 6850 2    60   ~ 0
GOB1
Text Label 9950 6850 0    60   ~ 0
GOB2
Text Label 9150 6950 2    60   ~ 0
GOB3
Text Label 9950 6950 0    60   ~ 0
GOB4
Text Label 9150 7050 2    60   ~ 0
GOB5
Text Label 9950 7050 0    60   ~ 0
GOB6
Text Label 9150 7150 2    60   ~ 0
GOB7
Text Label 9950 7150 0    60   ~ 0
GOB8
Text Label 11250 6950 2    60   ~ 0
GOB2
Text Label 11250 7050 2    60   ~ 0
GOB3
Text Label 11250 7150 2    60   ~ 0
GOB4
Text Label 11250 7250 2    60   ~ 0
GOB5
Text Label 11250 7350 2    60   ~ 0
GOB6
Text Label 11250 7450 2    60   ~ 0
GOB7
Text Label 11250 7550 2    60   ~ 0
GOB8
$Comp
L TLC590 U6
U 1 1 53A90916
P 12250 7300
F 0 "U6" H 12450 6000 60  0000 C CNN
F 1 "TLC590" H 12150 6000 60  0000 C CNN
F 2 "TLC5940:SSOP-28H" H 12250 7300 60  0001 C CNN
F 3 "" H 12250 7300 60  0000 C CNN
	1    12250 7300
	1    0    0    -1  
$EndComp
$Comp
L CONN_4X2 P14
U 1 1 53A9091C
P 9550 7600
F 0 "P14" H 9550 7850 50  0000 C CNN
F 1 "CONN_4X2" V 9550 7600 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 9550 7600 60  0001 C CNN
F 3 "" H 9550 7600 60  0000 C CNN
	1    9550 7600
	1    0    0    -1  
$EndComp
Text Label 9150 7450 2    60   ~ 0
GOB9
Text Label 9950 7450 0    60   ~ 0
GOB10
Text Label 9150 7550 2    60   ~ 0
GOB11
Text Label 9950 7550 0    60   ~ 0
GOB12
Text Label 9150 7650 2    60   ~ 0
GOB13
Text Label 9950 7650 0    60   ~ 0
GOB14
Text Label 9150 7750 2    60   ~ 0
GOB15
Text Label 9950 7750 0    60   ~ 0
GOB16
Text Label 11250 7650 2    60   ~ 0
GOB9
Text Label 11250 7750 2    60   ~ 0
GOB10
Text Label 11250 7850 2    60   ~ 0
GOB11
Text Label 11250 7950 2    60   ~ 0
GOB12
Text Label 11250 8050 2    60   ~ 0
GOB13
Text Label 11250 8150 2    60   ~ 0
GOB14
Text Label 11250 8250 2    60   ~ 0
GOB15
Text Label 11250 8350 2    60   ~ 0
GOB16
Text Label 12050 6500 1    60   ~ 0
vprg
Text Label 12250 6500 1    60   ~ 0
sclk
Text Label 12350 6500 1    60   ~ 0
xlat
Text Label 12450 6500 1    60   ~ 0
blank
Text Label 12550 6500 1    60   ~ 0
gnd
Text Label 13050 7850 0    60   ~ 0
vcc
Text Label 13050 8050 0    60   ~ 0
dcprg
Text Label 13050 8150 0    60   ~ 0
gsclk
Text Label 13050 8350 0    60   ~ 0
xerr
$Comp
L R R6
U 1 1 53A9093B
P 13550 7950
F 0 "R6" V 13630 7950 40  0000 C CNN
F 1 "R" V 13557 7951 40  0000 C CNN
F 2 "Resistors_SMD:Resistor_SMD0805_HandSoldering" V 13480 7950 30  0001 C CNN
F 3 "" H 13550 7950 30  0000 C CNN
	1    13550 7950
	0    1    1    0   
$EndComp
Wire Wire Line
	15950 8000 15950 7950
Wire Wire Line
	17750 7950 18000 7950
$Comp
L CONN_4X2 P11
U 1 1 53A90943
P 14250 7000
F 0 "P11" H 14250 7250 50  0000 C CNN
F 1 "CONN_4X2" V 14250 7000 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 14250 7000 60  0001 C CNN
F 3 "" H 14250 7000 60  0000 C CNN
	1    14250 7000
	-1   0    0    -1  
$EndComp
Text Label 13850 6850 2    60   ~ 0
GOC1
Text Label 15950 6850 2    60   ~ 0
GOC1
Text Label 14650 6850 0    60   ~ 0
GOC2
Text Label 13850 6950 2    60   ~ 0
GOC3
Text Label 14650 6950 0    60   ~ 0
GOC4
Text Label 13850 7050 2    60   ~ 0
GOC5
Text Label 14650 7050 0    60   ~ 0
GOC6
Text Label 13850 7150 2    60   ~ 0
GOC7
Text Label 14650 7150 0    60   ~ 0
GOC8
Text Label 15950 6950 2    60   ~ 0
GOC2
Text Label 15950 7050 2    60   ~ 0
GOC3
Text Label 15950 7150 2    60   ~ 0
GOC4
Text Label 15950 7250 2    60   ~ 0
GOC5
Text Label 15950 7350 2    60   ~ 0
GOC6
Text Label 15950 7450 2    60   ~ 0
GOC7
Text Label 15950 7550 2    60   ~ 0
GOC8
$Comp
L TLC590 U7
U 1 1 53A90959
P 16950 7300
F 0 "U7" H 17150 6000 60  0000 C CNN
F 1 "TLC590" H 16850 6000 60  0000 C CNN
F 2 "TLC5940:SSOP-28H" H 16950 7300 60  0001 C CNN
F 3 "" H 16950 7300 60  0000 C CNN
	1    16950 7300
	1    0    0    -1  
$EndComp
$Comp
L CONN_4X2 P15
U 1 1 53A9095F
P 14250 7600
F 0 "P15" H 14250 7850 50  0000 C CNN
F 1 "CONN_4X2" V 14250 7600 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 14250 7600 60  0001 C CNN
F 3 "" H 14250 7600 60  0000 C CNN
	1    14250 7600
	1    0    0    -1  
$EndComp
Text Label 13850 7450 2    60   ~ 0
GOC9
Text Label 14650 7450 0    60   ~ 0
GOC10
Text Label 13850 7550 2    60   ~ 0
GOC11
Text Label 14650 7550 0    60   ~ 0
GOC12
Text Label 13850 7650 2    60   ~ 0
GOC13
Text Label 14650 7650 0    60   ~ 0
GOC14
Text Label 13850 7750 2    60   ~ 0
GOC15
Text Label 14650 7750 0    60   ~ 0
GOC16
Text Label 15950 7650 2    60   ~ 0
GOC9
Text Label 15950 7750 2    60   ~ 0
GOC10
Text Label 15950 7850 2    60   ~ 0
GOC11
Text Label 15950 7950 2    60   ~ 0
GOC12
Text Label 15950 8050 2    60   ~ 0
GOC13
Text Label 15950 8150 2    60   ~ 0
GOC14
Text Label 15950 8250 2    60   ~ 0
GOC15
Text Label 15950 8350 2    60   ~ 0
GOC16
Text Label 16750 6500 1    60   ~ 0
vprg
Text Label 16950 6500 1    60   ~ 0
sclk
Text Label 17050 6500 1    60   ~ 0
xlat
Text Label 17150 6500 1    60   ~ 0
blank
Text Label 17250 6500 1    60   ~ 0
gnd
Text Label 17750 7850 0    60   ~ 0
vcc
Text Label 17750 8050 0    60   ~ 0
dcprg
Text Label 17750 8150 0    60   ~ 0
gsclk
Text Label 17750 8350 0    60   ~ 0
xerr
$Comp
L R R7
U 1 1 53A9097E
P 18250 7950
F 0 "R7" V 18330 7950 40  0000 C CNN
F 1 "R" V 18257 7951 40  0000 C CNN
F 2 "Resistors_SMD:Resistor_SMD0805_HandSoldering" V 18180 7950 30  0001 C CNN
F 3 "" H 18250 7950 30  0000 C CNN
	1    18250 7950
	0    1    1    0   
$EndComp
Wire Wire Line
	18500 7950 18650 7950
$Comp
L GND #PWR04
U 1 1 53A90985
P 18650 7950
F 0 "#PWR04" H 18650 7950 30  0001 C CNN
F 1 "GND" H 18650 7880 30  0001 C CNN
F 2 "" H 18650 7950 60  0000 C CNN
F 3 "" H 18650 7950 60  0000 C CNN
	1    18650 7950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	20650 8000 20650 7950
Wire Wire Line
	22450 7950 22700 7950
$Comp
L CONN_4X2 P12
U 1 1 53A9098D
P 18950 7000
F 0 "P12" H 18950 7250 50  0000 C CNN
F 1 "CONN_4X2" V 18950 7000 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 18950 7000 60  0001 C CNN
F 3 "" H 18950 7000 60  0000 C CNN
	1    18950 7000
	-1   0    0    -1  
$EndComp
Text Label 18550 6850 2    60   ~ 0
GOD1
Text Label 20650 6850 2    60   ~ 0
GOD1
Text Label 19350 6850 0    60   ~ 0
GOD2
Text Label 18550 6950 2    60   ~ 0
GOD3
Text Label 19350 6950 0    60   ~ 0
GOD4
Text Label 18550 7050 2    60   ~ 0
GOD5
Text Label 19350 7050 0    60   ~ 0
GOD6
Text Label 18550 7150 2    60   ~ 0
GOD7
Text Label 19350 7150 0    60   ~ 0
GOD8
Text Label 20650 6950 2    60   ~ 0
GOD2
Text Label 20650 7050 2    60   ~ 0
GOD3
Text Label 20650 7150 2    60   ~ 0
GOD4
Text Label 20650 7250 2    60   ~ 0
GOD5
Text Label 20650 7350 2    60   ~ 0
GOD6
Text Label 20650 7450 2    60   ~ 0
GOD7
Text Label 20650 7550 2    60   ~ 0
GOD8
$Comp
L TLC590 U8
U 1 1 53A909A3
P 21650 7300
F 0 "U8" H 21850 6000 60  0000 C CNN
F 1 "TLC590" H 21550 6000 60  0000 C CNN
F 2 "TLC5940:SSOP-28H" H 21650 7300 60  0001 C CNN
F 3 "" H 21650 7300 60  0000 C CNN
	1    21650 7300
	1    0    0    -1  
$EndComp
$Comp
L CONN_4X2 P16
U 1 1 53A909A9
P 18950 7600
F 0 "P16" H 18950 7850 50  0000 C CNN
F 1 "CONN_4X2" V 18950 7600 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 18950 7600 60  0001 C CNN
F 3 "" H 18950 7600 60  0000 C CNN
	1    18950 7600
	1    0    0    -1  
$EndComp
Text Label 18550 7450 2    60   ~ 0
GOD9
Text Label 19350 7450 0    60   ~ 0
GOD10
Text Label 18550 7550 2    60   ~ 0
GOD11
Text Label 19350 7550 0    60   ~ 0
GOD12
Text Label 18550 7650 2    60   ~ 0
GOD13
Text Label 19350 7650 0    60   ~ 0
GOD14
Text Label 18550 7750 2    60   ~ 0
GOD15
Text Label 19350 7750 0    60   ~ 0
GOD16
Text Label 20650 7650 2    60   ~ 0
GOD9
Text Label 20650 7750 2    60   ~ 0
GOD10
Text Label 20650 7850 2    60   ~ 0
GOD11
Text Label 20650 7950 2    60   ~ 0
GOD12
Text Label 20650 8050 2    60   ~ 0
GOD13
Text Label 20650 8150 2    60   ~ 0
GOD14
Text Label 20650 8250 2    60   ~ 0
GOD15
Text Label 20650 8350 2    60   ~ 0
GOD16
Text Label 21450 6500 1    60   ~ 0
vprg
Text Label 21650 6500 1    60   ~ 0
sclk
Text Label 21750 6500 1    60   ~ 0
xlat
Text Label 21850 6500 1    60   ~ 0
blank
Text Label 21950 6500 1    60   ~ 0
gnd
Text Label 22450 7850 0    60   ~ 0
vcc
Text Label 22450 8050 0    60   ~ 0
dcprg
Text Label 22450 8150 0    60   ~ 0
gsclk
Text Label 22450 8350 0    60   ~ 0
xerr
$Comp
L R R8
U 1 1 53A909C8
P 22950 7950
F 0 "R8" V 23030 7950 40  0000 C CNN
F 1 "R" V 22957 7951 40  0000 C CNN
F 2 "Resistors_SMD:Resistor_SMD0805_HandSoldering" V 22880 7950 30  0001 C CNN
F 3 "" H 22950 7950 30  0000 C CNN
	1    22950 7950
	0    1    1    0   
$EndComp
Wire Wire Line
	6500 10500 6500 10450
Wire Wire Line
	8300 10450 8550 10450
$Comp
L CONN_4X2 P17
U 1 1 53A91C66
P 4800 9500
F 0 "P17" H 4800 9750 50  0000 C CNN
F 1 "CONN_4X2" V 4800 9500 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 4800 9500 60  0001 C CNN
F 3 "" H 4800 9500 60  0000 C CNN
	1    4800 9500
	-1   0    0    -1  
$EndComp
Text Label 4400 9350 2    60   ~ 0
BOA1
Text Label 6500 9350 2    60   ~ 0
BOA1
Text Label 5200 9350 0    60   ~ 0
BOA2
Text Label 4400 9450 2    60   ~ 0
BOA3
Text Label 5200 9450 0    60   ~ 0
BOA4
Text Label 4400 9550 2    60   ~ 0
BOA5
Text Label 5200 9550 0    60   ~ 0
BOA6
Text Label 4400 9650 2    60   ~ 0
BOA7
Text Label 5200 9650 0    60   ~ 0
BOA8
Text Label 6500 9450 2    60   ~ 0
BOA2
Text Label 6500 9550 2    60   ~ 0
BOA3
Text Label 6500 9650 2    60   ~ 0
BOA4
Text Label 6500 9750 2    60   ~ 0
BOA5
Text Label 6500 9850 2    60   ~ 0
BOA6
Text Label 6500 9950 2    60   ~ 0
BOA7
Text Label 6500 10050 2    60   ~ 0
BOA8
$Comp
L TLC590 U9
U 1 1 53A91C7C
P 7500 9800
F 0 "U9" H 7700 8500 60  0000 C CNN
F 1 "TLC590" H 7400 8500 60  0000 C CNN
F 2 "TLC5940:SSOP-28H" H 7500 9800 60  0001 C CNN
F 3 "" H 7500 9800 60  0000 C CNN
	1    7500 9800
	1    0    0    -1  
$EndComp
$Comp
L CONN_4X2 P21
U 1 1 53A91C82
P 4800 10100
F 0 "P21" H 4800 10350 50  0000 C CNN
F 1 "CONN_4X2" V 4800 10100 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 4800 10100 60  0001 C CNN
F 3 "" H 4800 10100 60  0000 C CNN
	1    4800 10100
	1    0    0    -1  
$EndComp
Text Label 4400 9950 2    60   ~ 0
BOA9
Text Label 5200 9950 0    60   ~ 0
BOA10
Text Label 4400 10050 2    60   ~ 0
BOA11
Text Label 5200 10050 0    60   ~ 0
BOA12
Text Label 4400 10150 2    60   ~ 0
BOA13
Text Label 5200 10150 0    60   ~ 0
BOA14
Text Label 4400 10250 2    60   ~ 0
BOA15
Text Label 5200 10250 0    60   ~ 0
BOA16
Text Label 6500 10150 2    60   ~ 0
BOA9
Text Label 6500 10250 2    60   ~ 0
BOA10
Text Label 6500 10350 2    60   ~ 0
BOA11
Text Label 6500 10450 2    60   ~ 0
BOA12
Text Label 6500 10550 2    60   ~ 0
BOA13
Text Label 6500 10650 2    60   ~ 0
BOA14
Text Label 6500 10750 2    60   ~ 0
BOA15
Text Label 6500 10850 2    60   ~ 0
BOA16
Text Label 7300 9000 1    60   ~ 0
vprg
Text Label 7500 9000 1    60   ~ 0
sclk
Text Label 7600 9000 1    60   ~ 0
xlat
Text Label 7700 9000 1    60   ~ 0
blank
Text Label 7800 9000 1    60   ~ 0
gnd
Text Label 8300 10350 0    60   ~ 0
vcc
Text Label 8300 10550 0    60   ~ 0
dcprg
Text Label 8300 10650 0    60   ~ 0
gsclk
Text Label 8300 10850 0    60   ~ 0
xerr
$Comp
L R R9
U 1 1 53A91CA1
P 8800 10450
F 0 "R9" V 8880 10450 40  0000 C CNN
F 1 "R" V 8807 10451 40  0000 C CNN
F 2 "Resistors_SMD:Resistor_SMD0805_HandSoldering" V 8730 10450 30  0001 C CNN
F 3 "" H 8800 10450 30  0000 C CNN
	1    8800 10450
	0    1    1    0   
$EndComp
Wire Wire Line
	9050 10450 9200 10450
$Comp
L GND #PWR05
U 1 1 53A91CA8
P 9200 10450
F 0 "#PWR05" H 9200 10450 30  0001 C CNN
F 1 "GND" H 9200 10380 30  0001 C CNN
F 2 "" H 9200 10450 60  0000 C CNN
F 3 "" H 9200 10450 60  0000 C CNN
	1    9200 10450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	11200 10500 11200 10450
Wire Wire Line
	13000 10450 13250 10450
$Comp
L CONN_4X2 P18
U 1 1 53A91CB0
P 9500 9500
F 0 "P18" H 9500 9750 50  0000 C CNN
F 1 "CONN_4X2" V 9500 9500 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 9500 9500 60  0001 C CNN
F 3 "" H 9500 9500 60  0000 C CNN
	1    9500 9500
	-1   0    0    -1  
$EndComp
Text Label 9100 9350 2    60   ~ 0
BOB1
Text Label 11200 9350 2    60   ~ 0
BOB1
Text Label 9900 9350 0    60   ~ 0
BOB2
Text Label 9100 9450 2    60   ~ 0
BOB3
Text Label 9900 9450 0    60   ~ 0
BOB4
Text Label 9100 9550 2    60   ~ 0
BOB5
Text Label 9900 9550 0    60   ~ 0
BOB6
Text Label 9100 9650 2    60   ~ 0
BOB7
Text Label 9900 9650 0    60   ~ 0
BOB8
Text Label 11200 9450 2    60   ~ 0
BOB2
Text Label 11200 9550 2    60   ~ 0
BOB3
Text Label 11200 9650 2    60   ~ 0
BOB4
Text Label 11200 9750 2    60   ~ 0
BOB5
Text Label 11200 9850 2    60   ~ 0
BOB6
Text Label 11200 9950 2    60   ~ 0
BOB7
Text Label 11200 10050 2    60   ~ 0
BOB8
$Comp
L TLC590 U10
U 1 1 53A91CC6
P 12200 9800
F 0 "U10" H 12400 8500 60  0000 C CNN
F 1 "TLC590" H 12100 8500 60  0000 C CNN
F 2 "TLC5940:SSOP-28H" H 12200 9800 60  0001 C CNN
F 3 "" H 12200 9800 60  0000 C CNN
	1    12200 9800
	1    0    0    -1  
$EndComp
$Comp
L CONN_4X2 P22
U 1 1 53A91CCC
P 9500 10100
F 0 "P22" H 9500 10350 50  0000 C CNN
F 1 "CONN_4X2" V 9500 10100 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 9500 10100 60  0001 C CNN
F 3 "" H 9500 10100 60  0000 C CNN
	1    9500 10100
	1    0    0    -1  
$EndComp
Text Label 9100 9950 2    60   ~ 0
BOB9
Text Label 9900 9950 0    60   ~ 0
BOB10
Text Label 9100 10050 2    60   ~ 0
BOB11
Text Label 9900 10050 0    60   ~ 0
BOB12
Text Label 9100 10150 2    60   ~ 0
BOB13
Text Label 9900 10150 0    60   ~ 0
BOB14
Text Label 9100 10250 2    60   ~ 0
BOB15
Text Label 9900 10250 0    60   ~ 0
BOB16
Text Label 11200 10150 2    60   ~ 0
BOB9
Text Label 11200 10250 2    60   ~ 0
BOB10
Text Label 11200 10350 2    60   ~ 0
BOB11
Text Label 11200 10450 2    60   ~ 0
BOB12
Text Label 11200 10550 2    60   ~ 0
BOB13
Text Label 11200 10650 2    60   ~ 0
BOB14
Text Label 11200 10750 2    60   ~ 0
BOB15
Text Label 11200 10850 2    60   ~ 0
BOB16
Text Label 12000 9000 1    60   ~ 0
vprg
Text Label 12200 9000 1    60   ~ 0
sclk
Text Label 12300 9000 1    60   ~ 0
xlat
Text Label 12400 9000 1    60   ~ 0
blank
Text Label 12500 9000 1    60   ~ 0
gnd
Text Label 13000 10350 0    60   ~ 0
vcc
Text Label 13000 10550 0    60   ~ 0
dcprg
Text Label 13000 10650 0    60   ~ 0
gsclk
Text Label 13000 10850 0    60   ~ 0
xerr
$Comp
L R R10
U 1 1 53A91CEB
P 13500 10450
F 0 "R10" V 13580 10450 40  0000 C CNN
F 1 "R" V 13507 10451 40  0000 C CNN
F 2 "Resistors_SMD:Resistor_SMD0805_HandSoldering" V 13430 10450 30  0001 C CNN
F 3 "" H 13500 10450 30  0000 C CNN
	1    13500 10450
	0    1    1    0   
$EndComp
Wire Wire Line
	15900 10500 15900 10450
Wire Wire Line
	17700 10450 17950 10450
$Comp
L CONN_4X2 P19
U 1 1 53A91CF3
P 14200 9500
F 0 "P19" H 14200 9750 50  0000 C CNN
F 1 "CONN_4X2" V 14200 9500 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 14200 9500 60  0001 C CNN
F 3 "" H 14200 9500 60  0000 C CNN
	1    14200 9500
	-1   0    0    -1  
$EndComp
Text Label 13800 9350 2    60   ~ 0
BOC1
Text Label 15900 9350 2    60   ~ 0
BOC1
Text Label 14600 9350 0    60   ~ 0
BOC2
Text Label 13800 9450 2    60   ~ 0
BOC3
Text Label 14600 9450 0    60   ~ 0
BOC4
Text Label 13800 9550 2    60   ~ 0
BOC5
Text Label 14600 9550 0    60   ~ 0
BOC6
Text Label 13800 9650 2    60   ~ 0
BOC7
Text Label 14600 9650 0    60   ~ 0
BOC8
Text Label 15900 9450 2    60   ~ 0
BOC2
Text Label 15900 9550 2    60   ~ 0
BOC3
Text Label 15900 9650 2    60   ~ 0
BOC4
Text Label 15900 9750 2    60   ~ 0
BOC5
Text Label 15900 9850 2    60   ~ 0
BOC6
Text Label 15900 9950 2    60   ~ 0
BOC7
Text Label 15900 10050 2    60   ~ 0
BOC8
$Comp
L TLC590 U11
U 1 1 53A91D09
P 16900 9800
F 0 "U11" H 17100 8500 60  0000 C CNN
F 1 "TLC590" H 16800 8500 60  0000 C CNN
F 2 "TLC5940:SSOP-28H" H 16900 9800 60  0001 C CNN
F 3 "" H 16900 9800 60  0000 C CNN
	1    16900 9800
	1    0    0    -1  
$EndComp
$Comp
L CONN_4X2 P23
U 1 1 53A91D0F
P 14200 10100
F 0 "P23" H 14200 10350 50  0000 C CNN
F 1 "CONN_4X2" V 14200 10100 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 14200 10100 60  0001 C CNN
F 3 "" H 14200 10100 60  0000 C CNN
	1    14200 10100
	1    0    0    -1  
$EndComp
Text Label 13800 9950 2    60   ~ 0
BOC9
Text Label 14600 9950 0    60   ~ 0
BOC10
Text Label 13800 10050 2    60   ~ 0
BOC11
Text Label 14600 10050 0    60   ~ 0
BOC12
Text Label 13800 10150 2    60   ~ 0
BOC13
Text Label 14600 10150 0    60   ~ 0
BOC14
Text Label 13800 10250 2    60   ~ 0
BOC15
Text Label 14600 10250 0    60   ~ 0
BOC16
Text Label 15900 10150 2    60   ~ 0
BOC9
Text Label 15900 10250 2    60   ~ 0
BOC10
Text Label 15900 10350 2    60   ~ 0
BOC11
Text Label 15900 10450 2    60   ~ 0
BOC12
Text Label 15900 10550 2    60   ~ 0
BOC13
Text Label 15900 10650 2    60   ~ 0
BOC14
Text Label 15900 10750 2    60   ~ 0
BOC15
Text Label 15900 10850 2    60   ~ 0
BOC16
Text Label 16700 9000 1    60   ~ 0
vprg
Text Label 16900 9000 1    60   ~ 0
sclk
Text Label 17000 9000 1    60   ~ 0
xlat
Text Label 17100 9000 1    60   ~ 0
blank
Text Label 17200 9000 1    60   ~ 0
gnd
Text Label 17700 10350 0    60   ~ 0
vcc
Text Label 17700 10550 0    60   ~ 0
dcprg
Text Label 17700 10650 0    60   ~ 0
gsclk
Text Label 17700 10850 0    60   ~ 0
xerr
$Comp
L R R11
U 1 1 53A91D2E
P 18200 10450
F 0 "R11" V 18280 10450 40  0000 C CNN
F 1 "R" V 18207 10451 40  0000 C CNN
F 2 "Resistors_SMD:Resistor_SMD0805_HandSoldering" V 18130 10450 30  0001 C CNN
F 3 "" H 18200 10450 30  0000 C CNN
	1    18200 10450
	0    1    1    0   
$EndComp
Wire Wire Line
	18450 10450 18600 10450
$Comp
L GND #PWR06
U 1 1 53A91D35
P 18600 10450
F 0 "#PWR06" H 18600 10450 30  0001 C CNN
F 1 "GND" H 18600 10380 30  0001 C CNN
F 2 "" H 18600 10450 60  0000 C CNN
F 3 "" H 18600 10450 60  0000 C CNN
	1    18600 10450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	20600 10500 20600 10450
Wire Wire Line
	22400 10450 22650 10450
$Comp
L CONN_4X2 P20
U 1 1 53A91D3D
P 18900 9500
F 0 "P20" H 18900 9750 50  0000 C CNN
F 1 "CONN_4X2" V 18900 9500 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 18900 9500 60  0001 C CNN
F 3 "" H 18900 9500 60  0000 C CNN
	1    18900 9500
	-1   0    0    -1  
$EndComp
Text Label 18500 9350 2    60   ~ 0
BOD1
Text Label 20600 9350 2    60   ~ 0
BOD1
Text Label 19300 9350 0    60   ~ 0
BOD2
Text Label 18500 9450 2    60   ~ 0
BOD3
Text Label 19300 9450 0    60   ~ 0
BOD4
Text Label 18500 9550 2    60   ~ 0
BOD5
Text Label 19300 9550 0    60   ~ 0
BOD6
Text Label 18500 9650 2    60   ~ 0
BOD7
Text Label 19300 9650 0    60   ~ 0
BOD8
Text Label 20600 9450 2    60   ~ 0
BOD2
Text Label 20600 9550 2    60   ~ 0
BOD3
Text Label 20600 9650 2    60   ~ 0
BOD4
Text Label 20600 9750 2    60   ~ 0
BOD5
Text Label 20600 9850 2    60   ~ 0
BOD6
Text Label 20600 9950 2    60   ~ 0
BOD7
Text Label 20600 10050 2    60   ~ 0
BOD8
$Comp
L TLC590 U12
U 1 1 53A91D53
P 21600 9800
F 0 "U12" H 21800 8500 60  0000 C CNN
F 1 "TLC590" H 21500 8500 60  0000 C CNN
F 2 "TLC5940:SSOP-28H" H 21600 9800 60  0001 C CNN
F 3 "" H 21600 9800 60  0000 C CNN
	1    21600 9800
	1    0    0    -1  
$EndComp
$Comp
L CONN_4X2 P24
U 1 1 53A91D59
P 18900 10100
F 0 "P24" H 18900 10350 50  0000 C CNN
F 1 "CONN_4X2" V 18900 10100 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 18900 10100 60  0001 C CNN
F 3 "" H 18900 10100 60  0000 C CNN
	1    18900 10100
	1    0    0    -1  
$EndComp
Text Label 18500 9950 2    60   ~ 0
BOD9
Text Label 19300 9950 0    60   ~ 0
BOD10
Text Label 18500 10050 2    60   ~ 0
BOD11
Text Label 19300 10050 0    60   ~ 0
BOD12
Text Label 18500 10150 2    60   ~ 0
BOD13
Text Label 19300 10150 0    60   ~ 0
BOD14
Text Label 18500 10250 2    60   ~ 0
BOD15
Text Label 19300 10250 0    60   ~ 0
BOD16
Text Label 20600 10150 2    60   ~ 0
BOD9
Text Label 20600 10250 2    60   ~ 0
BOD10
Text Label 20600 10350 2    60   ~ 0
BOD11
Text Label 20600 10450 2    60   ~ 0
BOD12
Text Label 20600 10550 2    60   ~ 0
BOD13
Text Label 20600 10650 2    60   ~ 0
BOD14
Text Label 20600 10750 2    60   ~ 0
BOD15
Text Label 20600 10850 2    60   ~ 0
BOD16
Text Label 21400 9000 1    60   ~ 0
vprg
Text Label 21600 9000 1    60   ~ 0
sclk
Text Label 21700 9000 1    60   ~ 0
xlat
Text Label 21800 9000 1    60   ~ 0
blank
Text Label 21900 9000 1    60   ~ 0
gnd
Text Label 22400 10350 0    60   ~ 0
vcc
Text Label 22400 10550 0    60   ~ 0
dcprg
Text Label 22400 10650 0    60   ~ 0
gsclk
Text Label 22400 10850 0    60   ~ 0
xerr
$Comp
L R R12
U 1 1 53A91D78
P 22900 10450
F 0 "R12" V 22980 10450 40  0000 C CNN
F 1 "R" V 22907 10451 40  0000 C CNN
F 2 "Resistors_SMD:Resistor_SMD0805_HandSoldering" V 22830 10450 30  0001 C CNN
F 3 "" H 22900 10450 30  0000 C CNN
	1    22900 10450
	0    1    1    0   
$EndComp
Text Notes 2700 4250 0    60   ~ 0
RED_CHANNEL
Text Notes 2700 6800 0    60   ~ 0
GREEN_CHANNEL
Text Notes 2700 9300 0    60   ~ 0
BLUE_CHANNEL
Text Label 8350 5700 0    60   ~ 0
sin_B
Text Label 12150 3950 1    60   ~ 0
sin_B
Text Label 13050 5700 0    60   ~ 0
sin_C
Text Label 16850 3950 1    60   ~ 0
sin_C
Text Label 17750 5700 0    60   ~ 0
sin_D
Text Label 21550 3950 1    60   ~ 0
sin_D
Text Label 22450 5700 0    60   ~ 0
sin_E
Text Label 7450 6500 1    60   ~ 0
sin_E
Text Label 8350 8250 0    60   ~ 0
sin_F
Text Label 12150 6500 1    60   ~ 0
sin_F
Text Label 13050 8250 0    60   ~ 0
sin_G
Text Label 16850 6500 1    60   ~ 0
sin_G
Text Label 17750 8250 0    60   ~ 0
sin_H
Text Label 22450 8250 0    60   ~ 0
sin_I
Text Label 21550 6500 1    60   ~ 0
sin_H
Text Label 7400 9000 1    60   ~ 0
sin_I
Text Label 8300 10750 0    60   ~ 0
sin_J
Text Label 12100 9000 1    60   ~ 0
sin_J
Text Label 13000 10750 0    60   ~ 0
sin_K
Text Label 16800 9000 1    60   ~ 0
sin_K
Text Label 17700 10750 0    60   ~ 0
sin_L
Text Label 21500 9000 1    60   ~ 0
sin_L
Text Label 7450 3950 1    60   ~ 0
sin
$Comp
L C C1
U 1 1 53AAF7B4
P 8350 4150
F 0 "C1" H 8350 4250 40  0000 L CNN
F 1 "C" H 8356 4065 40  0000 L CNN
F 2 "Capacitors_SMD:c_0805" H 8388 4000 30  0001 C CNN
F 3 "" H 8350 4150 60  0000 C CNN
	1    8350 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 3950 8350 3950
Wire Wire Line
	8350 4350 8350 5300
$Comp
L C C2
U 1 1 53AAFCAD
P 13050 4150
F 0 "C2" H 13050 4250 40  0000 L CNN
F 1 "C" H 13056 4065 40  0000 L CNN
F 2 "Capacitors_SMD:c_0805" H 13088 4000 30  0001 C CNN
F 3 "" H 13050 4150 60  0000 C CNN
	1    13050 4150
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 53AAFE01
P 17750 4150
F 0 "C3" H 17750 4250 40  0000 L CNN
F 1 "C" H 17756 4065 40  0000 L CNN
F 2 "Capacitors_SMD:c_0805" H 17788 4000 30  0001 C CNN
F 3 "" H 17750 4150 60  0000 C CNN
	1    17750 4150
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 53AB0034
P 22450 4150
F 0 "C4" H 22450 4250 40  0000 L CNN
F 1 "C" H 22456 4065 40  0000 L CNN
F 2 "Capacitors_SMD:c_0805" H 22488 4000 30  0001 C CNN
F 3 "" H 22450 4150 60  0000 C CNN
	1    22450 4150
	1    0    0    -1  
$EndComp
$Comp
L C C8
U 1 1 53AB020C
P 22450 6700
F 0 "C8" H 22450 6800 40  0000 L CNN
F 1 "C" H 22456 6615 40  0000 L CNN
F 2 "Capacitors_SMD:c_0805" H 22488 6550 30  0001 C CNN
F 3 "" H 22450 6700 60  0000 C CNN
	1    22450 6700
	1    0    0    -1  
$EndComp
$Comp
L C C12
U 1 1 53AB04E2
P 22400 9200
F 0 "C12" H 22400 9300 40  0000 L CNN
F 1 "C" H 22406 9115 40  0000 L CNN
F 2 "Capacitors_SMD:c_0805" H 22438 9050 30  0001 C CNN
F 3 "" H 22400 9200 60  0000 C CNN
	1    22400 9200
	1    0    0    -1  
$EndComp
$Comp
L C C7
U 1 1 53AB06F8
P 17750 6700
F 0 "C7" H 17750 6800 40  0000 L CNN
F 1 "C" H 17756 6615 40  0000 L CNN
F 2 "Capacitors_SMD:c_0805" H 17788 6550 30  0001 C CNN
F 3 "" H 17750 6700 60  0000 C CNN
	1    17750 6700
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 53AB0905
P 8350 6700
F 0 "C5" H 8350 6800 40  0000 L CNN
F 1 "C" H 8356 6615 40  0000 L CNN
F 2 "Capacitors_SMD:c_0805" H 8388 6550 30  0001 C CNN
F 3 "" H 8350 6700 60  0000 C CNN
	1    8350 6700
	1    0    0    -1  
$EndComp
$Comp
L C C9
U 1 1 53AB0B41
P 8300 9200
F 0 "C9" H 8300 9300 40  0000 L CNN
F 1 "C" H 8306 9115 40  0000 L CNN
F 2 "Capacitors_SMD:c_0805" H 8338 9050 30  0001 C CNN
F 3 "" H 8300 9200 60  0000 C CNN
	1    8300 9200
	1    0    0    -1  
$EndComp
$Comp
L C C10
U 1 1 53AB0F86
P 13000 9200
F 0 "C10" H 13000 9300 40  0000 L CNN
F 1 "C" H 13006 9115 40  0000 L CNN
F 2 "Capacitors_SMD:c_0805" H 13038 9050 30  0001 C CNN
F 3 "" H 13000 9200 60  0000 C CNN
	1    13000 9200
	1    0    0    -1  
$EndComp
$Comp
L C C11
U 1 1 53AB11DC
P 17700 9200
F 0 "C11" H 17700 9300 40  0000 L CNN
F 1 "C" H 17706 9115 40  0000 L CNN
F 2 "Capacitors_SMD:c_0805" H 17738 9050 30  0001 C CNN
F 3 "" H 17700 9200 60  0000 C CNN
	1    17700 9200
	1    0    0    -1  
$EndComp
Wire Wire Line
	12550 3950 13050 3950
Wire Wire Line
	13050 4350 13050 5300
Wire Wire Line
	17250 3950 17750 3950
Wire Wire Line
	17750 4350 17750 5300
Wire Wire Line
	21950 3950 22450 3950
Wire Wire Line
	22450 4350 22450 5300
Wire Wire Line
	21950 6500 22450 6500
Wire Wire Line
	22450 6900 22450 7850
Wire Wire Line
	17250 6500 17750 6500
Wire Wire Line
	17750 6900 17750 7850
$Comp
L C C6
U 1 1 53AB20F2
P 13050 6700
F 0 "C6" H 13050 6800 40  0000 L CNN
F 1 "C" H 13056 6615 40  0000 L CNN
F 2 "Capacitors_SMD:c_0805" H 13088 6550 30  0001 C CNN
F 3 "" H 13050 6700 60  0000 C CNN
	1    13050 6700
	1    0    0    -1  
$EndComp
Wire Wire Line
	12550 6500 13050 6500
Wire Wire Line
	13050 6900 13050 7850
Wire Wire Line
	7850 6500 8350 6500
Wire Wire Line
	8350 7850 8350 6900
Wire Wire Line
	7800 9000 8300 9000
Wire Wire Line
	8300 9400 8300 10350
Wire Wire Line
	12500 9000 13000 9000
Wire Wire Line
	13000 9400 13000 10350
Wire Wire Line
	17200 9000 17700 9000
Wire Wire Line
	17700 9400 17700 10350
Wire Wire Line
	21900 9000 22400 9000
Wire Wire Line
	22400 9400 22400 10350
Wire Wire Line
	13800 5400 13950 5400
$Comp
L GND #PWR07
U 1 1 53AB3300
P 13950 5400
F 0 "#PWR07" H 13950 5400 30  0001 C CNN
F 1 "GND" H 13950 5330 30  0001 C CNN
F 2 "" H 13950 5400 60  0000 C CNN
F 3 "" H 13950 5400 60  0000 C CNN
	1    13950 5400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	23200 5400 23350 5400
$Comp
L GND #PWR08
U 1 1 53AB355F
P 23350 5400
F 0 "#PWR08" H 23350 5400 30  0001 C CNN
F 1 "GND" H 23350 5330 30  0001 C CNN
F 2 "" H 23350 5400 60  0000 C CNN
F 3 "" H 23350 5400 60  0000 C CNN
	1    23350 5400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	23200 7950 23350 7950
$Comp
L GND #PWR09
U 1 1 53AB3B7E
P 23350 7950
F 0 "#PWR09" H 23350 7950 30  0001 C CNN
F 1 "GND" H 23350 7880 30  0001 C CNN
F 2 "" H 23350 7950 60  0000 C CNN
F 3 "" H 23350 7950 60  0000 C CNN
	1    23350 7950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	23150 10450 23300 10450
$Comp
L GND #PWR010
U 1 1 53AB3DA1
P 23300 10450
F 0 "#PWR010" H 23300 10450 30  0001 C CNN
F 1 "GND" H 23300 10380 30  0001 C CNN
F 2 "" H 23300 10450 60  0000 C CNN
F 3 "" H 23300 10450 60  0000 C CNN
	1    23300 10450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	13800 7950 13950 7950
$Comp
L GND #PWR011
U 1 1 53AB40F0
P 13950 7950
F 0 "#PWR011" H 13950 7950 30  0001 C CNN
F 1 "GND" H 13950 7880 30  0001 C CNN
F 2 "" H 13950 7950 60  0000 C CNN
F 3 "" H 13950 7950 60  0000 C CNN
	1    13950 7950
	0    -1   -1   0   
$EndComp
Wire Wire Line
	13750 10450 13900 10450
$Comp
L GND #PWR012
U 1 1 53AB461F
P 13900 10450
F 0 "#PWR012" H 13900 10450 30  0001 C CNN
F 1 "GND" H 13900 10380 30  0001 C CNN
F 2 "" H 13900 10450 60  0000 C CNN
F 3 "" H 13900 10450 60  0000 C CNN
	1    13900 10450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4400 12350 4950 12350
Wire Wire Line
	4400 12500 4950 12500
Text Label 4400 12350 2    60   ~ 0
dcprg
Text Label 4400 12500 2    60   ~ 0
vprg
$Comp
L +3.3V #PWR013
U 1 1 53AB59E7
P 4950 12350
F 0 "#PWR013" H 4950 12310 30  0001 C CNN
F 1 "+3.3V" H 4950 12460 30  0000 C CNN
F 2 "" H 4950 12350 60  0000 C CNN
F 3 "" H 4950 12350 60  0000 C CNN
	1    4950 12350
	0    1    1    0   
$EndComp
Wire Wire Line
	13050 7850 13300 7850
$Comp
L +3.3V #PWR014
U 1 1 53AB623F
P 13300 7850
F 0 "#PWR014" H 13300 7810 30  0001 C CNN
F 1 "+3.3V" H 13300 7960 30  0000 C CNN
F 2 "" H 13300 7850 60  0000 C CNN
F 3 "" H 13300 7850 60  0000 C CNN
	1    13300 7850
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR015
U 1 1 53AB6996
P 13350 5300
F 0 "#PWR015" H 13350 5260 30  0001 C CNN
F 1 "+3.3V" H 13350 5410 30  0000 C CNN
F 2 "" H 13350 5300 60  0000 C CNN
F 3 "" H 13350 5300 60  0000 C CNN
	1    13350 5300
	0    1    1    0   
$EndComp
Wire Wire Line
	13050 5300 13350 5300
$Comp
L +3.3V #PWR016
U 1 1 53AB7431
P 8650 5300
F 0 "#PWR016" H 8650 5260 30  0001 C CNN
F 1 "+3.3V" H 8650 5410 30  0000 C CNN
F 2 "" H 8650 5300 60  0000 C CNN
F 3 "" H 8650 5300 60  0000 C CNN
	1    8650 5300
	0    1    1    0   
$EndComp
Wire Wire Line
	8350 5300 8650 5300
$Comp
L +3.3V #PWR017
U 1 1 53AB7A8C
P 18050 5300
F 0 "#PWR017" H 18050 5260 30  0001 C CNN
F 1 "+3.3V" H 18050 5410 30  0000 C CNN
F 2 "" H 18050 5300 60  0000 C CNN
F 3 "" H 18050 5300 60  0000 C CNN
	1    18050 5300
	0    1    1    0   
$EndComp
Wire Wire Line
	17750 5300 18050 5300
$Comp
L +3.3V #PWR018
U 1 1 53AB7CEB
P 22750 5300
F 0 "#PWR018" H 22750 5260 30  0001 C CNN
F 1 "+3.3V" H 22750 5410 30  0000 C CNN
F 2 "" H 22750 5300 60  0000 C CNN
F 3 "" H 22750 5300 60  0000 C CNN
	1    22750 5300
	0    1    1    0   
$EndComp
Wire Wire Line
	22450 5300 22750 5300
$Comp
L +3.3V #PWR019
U 1 1 53AB8562
P 8650 7850
F 0 "#PWR019" H 8650 7810 30  0001 C CNN
F 1 "+3.3V" H 8650 7960 30  0000 C CNN
F 2 "" H 8650 7850 60  0000 C CNN
F 3 "" H 8650 7850 60  0000 C CNN
	1    8650 7850
	0    1    1    0   
$EndComp
Wire Wire Line
	8350 7850 8650 7850
$Comp
L +3.3V #PWR020
U 1 1 53AB8EC9
P 18050 7850
F 0 "#PWR020" H 18050 7810 30  0001 C CNN
F 1 "+3.3V" H 18050 7960 30  0000 C CNN
F 2 "" H 18050 7850 60  0000 C CNN
F 3 "" H 18050 7850 60  0000 C CNN
	1    18050 7850
	0    1    1    0   
$EndComp
Wire Wire Line
	17750 7850 18050 7850
$Comp
L +3.3V #PWR021
U 1 1 53AB95D8
P 22750 7850
F 0 "#PWR021" H 22750 7810 30  0001 C CNN
F 1 "+3.3V" H 22750 7960 30  0000 C CNN
F 2 "" H 22750 7850 60  0000 C CNN
F 3 "" H 22750 7850 60  0000 C CNN
	1    22750 7850
	0    1    1    0   
$EndComp
Wire Wire Line
	22450 7850 22750 7850
$Comp
L +3.3V #PWR022
U 1 1 53AB9B43
P 8600 10350
F 0 "#PWR022" H 8600 10310 30  0001 C CNN
F 1 "+3.3V" H 8600 10460 30  0000 C CNN
F 2 "" H 8600 10350 60  0000 C CNN
F 3 "" H 8600 10350 60  0000 C CNN
	1    8600 10350
	0    1    1    0   
$EndComp
Wire Wire Line
	8300 10350 8600 10350
$Comp
L +3.3V #PWR023
U 1 1 53AB9F46
P 13300 10350
F 0 "#PWR023" H 13300 10310 30  0001 C CNN
F 1 "+3.3V" H 13300 10460 30  0000 C CNN
F 2 "" H 13300 10350 60  0000 C CNN
F 3 "" H 13300 10350 60  0000 C CNN
	1    13300 10350
	0    1    1    0   
$EndComp
Wire Wire Line
	13000 10350 13300 10350
$Comp
L +3.3V #PWR024
U 1 1 53ABA21D
P 18000 10350
F 0 "#PWR024" H 18000 10310 30  0001 C CNN
F 1 "+3.3V" H 18000 10460 30  0000 C CNN
F 2 "" H 18000 10350 60  0000 C CNN
F 3 "" H 18000 10350 60  0000 C CNN
	1    18000 10350
	0    1    1    0   
$EndComp
Wire Wire Line
	17700 10350 18000 10350
$Comp
L +3.3V #PWR025
U 1 1 53ABA5A8
P 22700 10350
F 0 "#PWR025" H 22700 10310 30  0001 C CNN
F 1 "+3.3V" H 22700 10460 30  0000 C CNN
F 2 "" H 22700 10350 60  0000 C CNN
F 3 "" H 22700 10350 60  0000 C CNN
	1    22700 10350
	0    1    1    0   
$EndComp
Wire Wire Line
	22400 10350 22700 10350
Text Label 4400 12700 2    60   ~ 0
blank
Text Label 4400 12800 2    60   ~ 0
sclk
Text Label 5200 12700 0    60   ~ 0
gsclk
Text Label 4400 13000 2    60   ~ 0
xlat
Text Label 4400 12900 2    60   ~ 0
sin
Wire Wire Line
	4400 12700 3700 12700
$Comp
L R R13
U 1 1 53ABD2DF
P 3450 12700
F 0 "R13" V 3530 12700 40  0000 C CNN
F 1 "R" V 3457 12701 40  0000 C CNN
F 2 "Resistors_SMD:Resistor_SMD0805_HandSoldering" V 3380 12700 30  0001 C CNN
F 3 "" H 3450 12700 30  0000 C CNN
	1    3450 12700
	0    1    1    0   
$EndComp
Wire Wire Line
	3200 12700 3100 12700
$Comp
L +3.3V #PWR026
U 1 1 53ABD4EC
P 3100 12700
F 0 "#PWR026" H 3100 12660 30  0001 C CNN
F 1 "+3.3V" H 3100 12810 30  0000 C CNN
F 2 "" H 3100 12700 60  0000 C CNN
F 3 "" H 3100 12700 60  0000 C CNN
	1    3100 12700
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR028
U 1 1 53ABF2A1
P 7950 3950
F 0 "#PWR028" H 7950 3950 30  0001 C CNN
F 1 "GND" H 7950 3880 30  0001 C CNN
F 2 "" H 7950 3950 60  0000 C CNN
F 3 "" H 7950 3950 60  0000 C CNN
	1    7950 3950
	0    -1   -1   0   
$EndComp
Text Label 5200 12800 0    60   ~ 0
gnd
Text Label 5200 12900 0    60   ~ 0
vcc
$Comp
L CONN_4X2 P26
U 1 1 54027DB9
P 7250 12850
F 0 "P26" H 7250 13100 50  0000 C CNN
F 1 "CONN_4X2" V 7250 12850 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 7250 12850 60  0001 C CNN
F 3 "" H 7250 12850 60  0000 C CNN
	1    7250 12850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6850 12700 6650 12700
Wire Wire Line
	7650 12700 7850 12700
Wire Wire Line
	7650 12800 7850 12800
Wire Wire Line
	7650 12900 7850 12900
Wire Wire Line
	7650 13000 7850 13000
Wire Wire Line
	6850 12800 6650 12800
Wire Wire Line
	6850 12900 6650 12900
Wire Wire Line
	6850 13000 6650 13000
Text Label 6650 12700 2    60   ~ 0
L1
Text Label 7850 12700 0    60   ~ 0
L2
Text Label 6650 12800 2    60   ~ 0
L3
Text Label 6650 12900 2    60   ~ 0
L5
Text Label 6650 13000 2    60   ~ 0
L7
Text Label 7850 12800 0    60   ~ 0
L4
Text Label 7850 12900 0    60   ~ 0
L6
Text Label 7850 13000 0    60   ~ 0
L8
$Comp
L CONN_4X2 P27
U 1 1 5402961E
P 9250 12850
F 0 "P27" H 9250 13100 50  0000 C CNN
F 1 "CONN_4X2" V 9250 12850 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 9250 12850 60  0001 C CNN
F 3 "" H 9250 12850 60  0000 C CNN
	1    9250 12850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 12700 8650 12700
Wire Wire Line
	9650 12700 9850 12700
Wire Wire Line
	9650 12800 9850 12800
Wire Wire Line
	9650 12900 9850 12900
Wire Wire Line
	9650 13000 9850 13000
Wire Wire Line
	8850 12800 8650 12800
Wire Wire Line
	8850 12900 8650 12900
Wire Wire Line
	8850 13000 8650 13000
Text Label 8650 12700 2    60   ~ 0
L1
Text Label 9850 12700 0    60   ~ 0
L2
Text Label 8650 12800 2    60   ~ 0
L3
Text Label 8650 12900 2    60   ~ 0
L5
Text Label 8650 13000 2    60   ~ 0
L7
Text Label 9850 12800 0    60   ~ 0
L4
Text Label 9850 12900 0    60   ~ 0
L6
Text Label 9850 13000 0    60   ~ 0
L8
$Comp
L CONN_4X2 P25
U 1 1 5402A283
P 4800 12850
F 0 "P25" H 4800 13100 50  0000 C CNN
F 1 "CONN_4X2" V 4800 12850 40  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x04" H 4800 12850 60  0001 C CNN
F 3 "" H 4800 12850 60  0000 C CNN
	1    4800 12850
	1    0    0    -1  
$EndComp
NoConn ~ 5200 13000
NoConn ~ 21800 4150
NoConn ~ 4950 12500
$EndSCHEMATC
