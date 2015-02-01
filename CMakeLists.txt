cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ../Platform/LPC1769.cmake)

project(Led_CUBE C)


include_directories(
	
	Software/FastPWM/
	Software/TLC5940/
	Software/SPI_SSP/
	Software/liblpc-inc/
	Software/LEDCUBE/
)
set(SOURCES

	Software/src/cr_startup_lpc176x.c
	Software/src/main.c
	Software/FastPWM/FastPWM.c


	Software/liblpc-src/lpc17xx_clkpwr.c
	Software/liblpc-src/lpc17xx_ssp.c
	Software/liblpc-src/lpc17xx_pwm.c
	Software/liblpc-src/lpc17xx_gpdma.c
	Software/liblpc-src/lpc17xx_pinsel.c
	Software/liblpc-src/lpc17xx_libcfg_default.c
	Software/SPI_SSP/spi.c
	Software/TLC5940/TLC5940.c
	Software/LEDCUBE/ledcube.c

)

add_definitions(
-Wall
-Wno-error=cast-qual
)

# Debug builds by default, uncomment for Release:
# set(CMAKE_RELEASE True)

# Uncomment to enable Semihosting (required to even link against
# semihosting libraries)
# set(SEMIHOSTING_ENABLED True)

include(../Platform/LPC1769_project_default.cmake)
include(../Platform/LPC1769_targets.cmake)

