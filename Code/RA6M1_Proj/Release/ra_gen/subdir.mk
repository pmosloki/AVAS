################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra_gen/common_data.c \
../ra_gen/hal_data.c \
../ra_gen/main.c \
../ra_gen/pin_data.c \
../ra_gen/vector_data.c 

C_DEPS += \
./ra_gen/common_data.d \
./ra_gen/hal_data.d \
./ra_gen/main.d \
./ra_gen/pin_data.d \
./ra_gen/vector_data.d 

OBJS += \
./ra_gen/common_data.o \
./ra_gen/hal_data.o \
./ra_gen/main.o \
./ra_gen/pin_data.o \
./ra_gen/vector_data.o 

SREC += \
RA6M1_Proj.srec 

MAP += \
RA6M1_Proj.map 


# Each subdirectory must supply rules for building sources it contributes
ra_gen/%.o: ../ra_gen/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RA_CORE=CM4 -D_RENESAS_RA_ -I"E:/UDS/DEMO/workspace_3_backup/Workspace_3/RA6M1_Proj/src" -I"E:/UDS/DEMO/workspace_3_backup/Workspace_3/RA6M1_Proj/ra/fsp/inc" -I"E:/UDS/DEMO/workspace_3_backup/Workspace_3/RA6M1_Proj/ra/fsp/inc/api" -I"E:/UDS/DEMO/workspace_3_backup/Workspace_3/RA6M1_Proj/ra/fsp/inc/instances" -I"E:/UDS/DEMO/workspace_3_backup/Workspace_3/RA6M1_Proj/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"E:/UDS/DEMO/workspace_3_backup/Workspace_3/RA6M1_Proj/ra_gen" -I"E:/UDS/DEMO/workspace_3_backup/Workspace_3/RA6M1_Proj/ra_cfg/fsp_cfg/bsp" -I"E:/UDS/DEMO/workspace_3_backup/Workspace_3/RA6M1_Proj/ra_cfg/fsp_cfg" -I"E:/UDS/DEMO/workspace_3_backup/Workspace_3/RA6M1_Proj/ADPCM_LIB" -I"E:/UDS/DEMO/workspace_3_backup/Workspace_3/RA6M1_Proj/APPLICATION" -I"E:/UDS/DEMO/workspace_3_backup/Workspace_3/RA6M1_Proj/test_app" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

