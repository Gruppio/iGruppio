#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile

# Environment
MKDIR=mkdir -p
RM=rm -f 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/IGruppioV2.X.${IMAGE_TYPE}.elf
else
IMAGE_TYPE=production
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/IGruppioV2.X.${IMAGE_TYPE}.elf
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/Adc-Gruppio.o ${OBJECTDIR}/_ext/1472/Adxl345.o ${OBJECTDIR}/_ext/1472/App.o ${OBJECTDIR}/_ext/1472/Filter.o ${OBJECTDIR}/_ext/1472/Grapichs.o ${OBJECTDIR}/_ext/1472/HMC6352.o ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o ${OBJECTDIR}/_ext/1472/IGruppioV2.o ${OBJECTDIR}/_ext/1472/ITG3200.o ${OBJECTDIR}/_ext/1472/MLX90614.o ${OBJECTDIR}/_ext/1472/Pic32mx7.o ${OBJECTDIR}/_ext/1472/PicasoSGC.o ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

# Path to java used to run MPLAB X when this makefile was created
MP_JAVA_PATH=/System/Library/Java/JavaVirtualMachines/1.6.0.jdk/Contents/Home/bin/
OS_CURRENT="$(shell uname -s)"
############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
MP_CC=/Applications/microchip/mplabc32/v2.00/bin/pic32-gcc
# MP_BC is not defined
MP_AS=/Applications/microchip/mplabc32/v2.00/bin/pic32-as
MP_LD=/Applications/microchip/mplabc32/v2.00/bin/pic32-ld
MP_AR=/Applications/microchip/mplabc32/v2.00/bin/pic32-ar
# MP_BC is not defined
MP_CC_DIR=/Applications/microchip/mplabc32/v2.00/bin
# MP_BC_DIR is not defined
MP_AS_DIR=/Applications/microchip/mplabc32/v2.00/bin
MP_LD_DIR=/Applications/microchip/mplabc32/v2.00/bin
MP_AR_DIR=/Applications/microchip/mplabc32/v2.00/bin
# MP_BC_DIR is not defined

.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/IGruppioV2.X.${IMAGE_TYPE}.elf

MP_PROCESSOR_OPTION=32MX795F512L
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/Filter.o: ../Filter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Filter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Filter.o.ok ${OBJECTDIR}/_ext/1472/Filter.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Filter.o.d -o ${OBJECTDIR}/_ext/1472/Filter.o ../Filter.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Filter.o.d -o ${OBJECTDIR}/_ext/1472/Filter.o ../Filter.c   > ${OBJECTDIR}/_ext/1472/Filter.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Filter.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Filter.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Filter.o.d > ${OBJECTDIR}/_ext/1472/Filter.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Filter.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Filter.o.tmp ${OBJECTDIR}/_ext/1472/Filter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Filter.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Filter.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Filter.o.ok; else cat ${OBJECTDIR}/_ext/1472/Filter.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Uart-Gruppio.o: ../Uart-Gruppio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.ok ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o ../Uart-Gruppio.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o ../Uart-Gruppio.c   > ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d > ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.tmp ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.ok; else cat ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/MLX90614.o: ../MLX90614.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/MLX90614.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MLX90614.o.ok ${OBJECTDIR}/_ext/1472/MLX90614.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/MLX90614.o.d -o ${OBJECTDIR}/_ext/1472/MLX90614.o ../MLX90614.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/MLX90614.o.d -o ${OBJECTDIR}/_ext/1472/MLX90614.o ../MLX90614.c   > ${OBJECTDIR}/_ext/1472/MLX90614.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/MLX90614.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/MLX90614.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/MLX90614.o.d > ${OBJECTDIR}/_ext/1472/MLX90614.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/MLX90614.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/MLX90614.o.tmp ${OBJECTDIR}/_ext/1472/MLX90614.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MLX90614.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/MLX90614.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/MLX90614.o.ok; else cat ${OBJECTDIR}/_ext/1472/MLX90614.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/ITG3200.o: ../ITG3200.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/ITG3200.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ITG3200.o.ok ${OBJECTDIR}/_ext/1472/ITG3200.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/ITG3200.o.d -o ${OBJECTDIR}/_ext/1472/ITG3200.o ../ITG3200.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/ITG3200.o.d -o ${OBJECTDIR}/_ext/1472/ITG3200.o ../ITG3200.c   > ${OBJECTDIR}/_ext/1472/ITG3200.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/ITG3200.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/ITG3200.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/ITG3200.o.d > ${OBJECTDIR}/_ext/1472/ITG3200.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/ITG3200.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/ITG3200.o.tmp ${OBJECTDIR}/_ext/1472/ITG3200.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ITG3200.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/ITG3200.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/ITG3200.o.ok; else cat ${OBJECTDIR}/_ext/1472/ITG3200.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Adxl345.o: ../Adxl345.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Adxl345.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Adxl345.o.ok ${OBJECTDIR}/_ext/1472/Adxl345.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Adxl345.o.d -o ${OBJECTDIR}/_ext/1472/Adxl345.o ../Adxl345.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Adxl345.o.d -o ${OBJECTDIR}/_ext/1472/Adxl345.o ../Adxl345.c   > ${OBJECTDIR}/_ext/1472/Adxl345.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Adxl345.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Adxl345.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Adxl345.o.d > ${OBJECTDIR}/_ext/1472/Adxl345.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Adxl345.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Adxl345.o.tmp ${OBJECTDIR}/_ext/1472/Adxl345.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Adxl345.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Adxl345.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Adxl345.o.ok; else cat ${OBJECTDIR}/_ext/1472/Adxl345.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/IGruppioV2.o: ../IGruppioV2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/IGruppioV2.o.ok ${OBJECTDIR}/_ext/1472/IGruppioV2.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d -o ${OBJECTDIR}/_ext/1472/IGruppioV2.o ../IGruppioV2.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d -o ${OBJECTDIR}/_ext/1472/IGruppioV2.o ../IGruppioV2.c   > ${OBJECTDIR}/_ext/1472/IGruppioV2.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/IGruppioV2.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d > ${OBJECTDIR}/_ext/1472/IGruppioV2.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/IGruppioV2.o.tmp ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/IGruppioV2.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/IGruppioV2.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/IGruppioV2.o.ok; else cat ${OBJECTDIR}/_ext/1472/IGruppioV2.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/HMC6352.o: ../HMC6352.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/HMC6352.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/HMC6352.o.ok ${OBJECTDIR}/_ext/1472/HMC6352.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/HMC6352.o.d -o ${OBJECTDIR}/_ext/1472/HMC6352.o ../HMC6352.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/HMC6352.o.d -o ${OBJECTDIR}/_ext/1472/HMC6352.o ../HMC6352.c   > ${OBJECTDIR}/_ext/1472/HMC6352.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/HMC6352.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/HMC6352.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/HMC6352.o.d > ${OBJECTDIR}/_ext/1472/HMC6352.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/HMC6352.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/HMC6352.o.tmp ${OBJECTDIR}/_ext/1472/HMC6352.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/HMC6352.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/HMC6352.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/HMC6352.o.ok; else cat ${OBJECTDIR}/_ext/1472/HMC6352.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Adc-Gruppio.o: ../Adc-Gruppio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.ok ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o ../Adc-Gruppio.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o ../Adc-Gruppio.c   > ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d > ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.tmp ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.ok; else cat ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Grapichs.o: ../Grapichs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Grapichs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Grapichs.o.ok ${OBJECTDIR}/_ext/1472/Grapichs.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Grapichs.o.d -o ${OBJECTDIR}/_ext/1472/Grapichs.o ../Grapichs.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Grapichs.o.d -o ${OBJECTDIR}/_ext/1472/Grapichs.o ../Grapichs.c   > ${OBJECTDIR}/_ext/1472/Grapichs.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Grapichs.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Grapichs.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Grapichs.o.d > ${OBJECTDIR}/_ext/1472/Grapichs.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Grapichs.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Grapichs.o.tmp ${OBJECTDIR}/_ext/1472/Grapichs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Grapichs.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Grapichs.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Grapichs.o.ok; else cat ${OBJECTDIR}/_ext/1472/Grapichs.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o: ../I2C\ -\ Gruppio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.ok ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o ../I2C\ -\ Gruppio.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o ../I2C\ -\ Gruppio.c   > ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d > ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.tmp ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.ok; else cat ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Pic32mx7.o: ../Pic32mx7.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Pic32mx7.o.ok ${OBJECTDIR}/_ext/1472/Pic32mx7.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d -o ${OBJECTDIR}/_ext/1472/Pic32mx7.o ../Pic32mx7.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d -o ${OBJECTDIR}/_ext/1472/Pic32mx7.o ../Pic32mx7.c   > ${OBJECTDIR}/_ext/1472/Pic32mx7.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Pic32mx7.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d > ${OBJECTDIR}/_ext/1472/Pic32mx7.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Pic32mx7.o.tmp ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Pic32mx7.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Pic32mx7.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Pic32mx7.o.ok; else cat ${OBJECTDIR}/_ext/1472/Pic32mx7.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/App.o: ../App.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/App.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/App.o.ok ${OBJECTDIR}/_ext/1472/App.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/App.o.d -o ${OBJECTDIR}/_ext/1472/App.o ../App.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/App.o.d -o ${OBJECTDIR}/_ext/1472/App.o ../App.c   > ${OBJECTDIR}/_ext/1472/App.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/App.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/App.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/App.o.d > ${OBJECTDIR}/_ext/1472/App.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/App.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/App.o.tmp ${OBJECTDIR}/_ext/1472/App.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/App.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/App.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/App.o.ok; else cat ${OBJECTDIR}/_ext/1472/App.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/PicasoSGC.o: ../PicasoSGC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PicasoSGC.o.ok ${OBJECTDIR}/_ext/1472/PicasoSGC.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d -o ${OBJECTDIR}/_ext/1472/PicasoSGC.o ../PicasoSGC.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d -o ${OBJECTDIR}/_ext/1472/PicasoSGC.o ../PicasoSGC.c   > ${OBJECTDIR}/_ext/1472/PicasoSGC.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/PicasoSGC.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d > ${OBJECTDIR}/_ext/1472/PicasoSGC.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/PicasoSGC.o.tmp ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PicasoSGC.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/PicasoSGC.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/PicasoSGC.o.ok; else cat ${OBJECTDIR}/_ext/1472/PicasoSGC.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o: ../Timer-PWM-Gruppio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.ok ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o ../Timer-PWM-Gruppio.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o ../Timer-PWM-Gruppio.c   > ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d > ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.tmp ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.ok; else cat ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.err; exit 1; fi
	
else
${OBJECTDIR}/_ext/1472/Filter.o: ../Filter.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Filter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Filter.o.ok ${OBJECTDIR}/_ext/1472/Filter.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Filter.o.d -o ${OBJECTDIR}/_ext/1472/Filter.o ../Filter.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Filter.o.d -o ${OBJECTDIR}/_ext/1472/Filter.o ../Filter.c   > ${OBJECTDIR}/_ext/1472/Filter.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Filter.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Filter.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Filter.o.d > ${OBJECTDIR}/_ext/1472/Filter.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Filter.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Filter.o.tmp ${OBJECTDIR}/_ext/1472/Filter.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Filter.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Filter.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Filter.o.ok; else cat ${OBJECTDIR}/_ext/1472/Filter.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Uart-Gruppio.o: ../Uart-Gruppio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.ok ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o ../Uart-Gruppio.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o ../Uart-Gruppio.c   > ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d > ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.tmp ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.ok; else cat ${OBJECTDIR}/_ext/1472/Uart-Gruppio.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/MLX90614.o: ../MLX90614.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/MLX90614.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MLX90614.o.ok ${OBJECTDIR}/_ext/1472/MLX90614.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/MLX90614.o.d -o ${OBJECTDIR}/_ext/1472/MLX90614.o ../MLX90614.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/MLX90614.o.d -o ${OBJECTDIR}/_ext/1472/MLX90614.o ../MLX90614.c   > ${OBJECTDIR}/_ext/1472/MLX90614.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/MLX90614.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/MLX90614.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/MLX90614.o.d > ${OBJECTDIR}/_ext/1472/MLX90614.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/MLX90614.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/MLX90614.o.tmp ${OBJECTDIR}/_ext/1472/MLX90614.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/MLX90614.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/MLX90614.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/MLX90614.o.ok; else cat ${OBJECTDIR}/_ext/1472/MLX90614.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/ITG3200.o: ../ITG3200.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/ITG3200.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ITG3200.o.ok ${OBJECTDIR}/_ext/1472/ITG3200.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/ITG3200.o.d -o ${OBJECTDIR}/_ext/1472/ITG3200.o ../ITG3200.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/ITG3200.o.d -o ${OBJECTDIR}/_ext/1472/ITG3200.o ../ITG3200.c   > ${OBJECTDIR}/_ext/1472/ITG3200.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/ITG3200.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/ITG3200.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/ITG3200.o.d > ${OBJECTDIR}/_ext/1472/ITG3200.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/ITG3200.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/ITG3200.o.tmp ${OBJECTDIR}/_ext/1472/ITG3200.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/ITG3200.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/ITG3200.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/ITG3200.o.ok; else cat ${OBJECTDIR}/_ext/1472/ITG3200.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Adxl345.o: ../Adxl345.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Adxl345.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Adxl345.o.ok ${OBJECTDIR}/_ext/1472/Adxl345.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Adxl345.o.d -o ${OBJECTDIR}/_ext/1472/Adxl345.o ../Adxl345.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Adxl345.o.d -o ${OBJECTDIR}/_ext/1472/Adxl345.o ../Adxl345.c   > ${OBJECTDIR}/_ext/1472/Adxl345.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Adxl345.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Adxl345.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Adxl345.o.d > ${OBJECTDIR}/_ext/1472/Adxl345.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Adxl345.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Adxl345.o.tmp ${OBJECTDIR}/_ext/1472/Adxl345.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Adxl345.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Adxl345.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Adxl345.o.ok; else cat ${OBJECTDIR}/_ext/1472/Adxl345.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/IGruppioV2.o: ../IGruppioV2.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/IGruppioV2.o.ok ${OBJECTDIR}/_ext/1472/IGruppioV2.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d -o ${OBJECTDIR}/_ext/1472/IGruppioV2.o ../IGruppioV2.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d -o ${OBJECTDIR}/_ext/1472/IGruppioV2.o ../IGruppioV2.c   > ${OBJECTDIR}/_ext/1472/IGruppioV2.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/IGruppioV2.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d > ${OBJECTDIR}/_ext/1472/IGruppioV2.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/IGruppioV2.o.tmp ${OBJECTDIR}/_ext/1472/IGruppioV2.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/IGruppioV2.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/IGruppioV2.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/IGruppioV2.o.ok; else cat ${OBJECTDIR}/_ext/1472/IGruppioV2.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/HMC6352.o: ../HMC6352.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/HMC6352.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/HMC6352.o.ok ${OBJECTDIR}/_ext/1472/HMC6352.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/HMC6352.o.d -o ${OBJECTDIR}/_ext/1472/HMC6352.o ../HMC6352.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/HMC6352.o.d -o ${OBJECTDIR}/_ext/1472/HMC6352.o ../HMC6352.c   > ${OBJECTDIR}/_ext/1472/HMC6352.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/HMC6352.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/HMC6352.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/HMC6352.o.d > ${OBJECTDIR}/_ext/1472/HMC6352.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/HMC6352.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/HMC6352.o.tmp ${OBJECTDIR}/_ext/1472/HMC6352.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/HMC6352.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/HMC6352.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/HMC6352.o.ok; else cat ${OBJECTDIR}/_ext/1472/HMC6352.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Adc-Gruppio.o: ../Adc-Gruppio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.ok ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o ../Adc-Gruppio.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o ../Adc-Gruppio.c   > ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d > ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.tmp ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.ok; else cat ${OBJECTDIR}/_ext/1472/Adc-Gruppio.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Grapichs.o: ../Grapichs.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Grapichs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Grapichs.o.ok ${OBJECTDIR}/_ext/1472/Grapichs.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Grapichs.o.d -o ${OBJECTDIR}/_ext/1472/Grapichs.o ../Grapichs.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Grapichs.o.d -o ${OBJECTDIR}/_ext/1472/Grapichs.o ../Grapichs.c   > ${OBJECTDIR}/_ext/1472/Grapichs.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Grapichs.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Grapichs.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Grapichs.o.d > ${OBJECTDIR}/_ext/1472/Grapichs.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Grapichs.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Grapichs.o.tmp ${OBJECTDIR}/_ext/1472/Grapichs.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Grapichs.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Grapichs.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Grapichs.o.ok; else cat ${OBJECTDIR}/_ext/1472/Grapichs.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o: ../I2C\ -\ Gruppio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.ok ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o ../I2C\ -\ Gruppio.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o ../I2C\ -\ Gruppio.c   > ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d > ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.tmp ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.ok; else cat ${OBJECTDIR}/_ext/1472/I2C\ -\ Gruppio.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Pic32mx7.o: ../Pic32mx7.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Pic32mx7.o.ok ${OBJECTDIR}/_ext/1472/Pic32mx7.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d -o ${OBJECTDIR}/_ext/1472/Pic32mx7.o ../Pic32mx7.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d -o ${OBJECTDIR}/_ext/1472/Pic32mx7.o ../Pic32mx7.c   > ${OBJECTDIR}/_ext/1472/Pic32mx7.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Pic32mx7.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d > ${OBJECTDIR}/_ext/1472/Pic32mx7.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Pic32mx7.o.tmp ${OBJECTDIR}/_ext/1472/Pic32mx7.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Pic32mx7.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Pic32mx7.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Pic32mx7.o.ok; else cat ${OBJECTDIR}/_ext/1472/Pic32mx7.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/App.o: ../App.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/App.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/App.o.ok ${OBJECTDIR}/_ext/1472/App.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/App.o.d -o ${OBJECTDIR}/_ext/1472/App.o ../App.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/App.o.d -o ${OBJECTDIR}/_ext/1472/App.o ../App.c   > ${OBJECTDIR}/_ext/1472/App.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/App.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/App.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/App.o.d > ${OBJECTDIR}/_ext/1472/App.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/App.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/App.o.tmp ${OBJECTDIR}/_ext/1472/App.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/App.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/App.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/App.o.ok; else cat ${OBJECTDIR}/_ext/1472/App.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/PicasoSGC.o: ../PicasoSGC.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PicasoSGC.o.ok ${OBJECTDIR}/_ext/1472/PicasoSGC.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d -o ${OBJECTDIR}/_ext/1472/PicasoSGC.o ../PicasoSGC.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d -o ${OBJECTDIR}/_ext/1472/PicasoSGC.o ../PicasoSGC.c   > ${OBJECTDIR}/_ext/1472/PicasoSGC.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/PicasoSGC.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d > ${OBJECTDIR}/_ext/1472/PicasoSGC.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/PicasoSGC.o.tmp ${OBJECTDIR}/_ext/1472/PicasoSGC.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/PicasoSGC.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/PicasoSGC.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/PicasoSGC.o.ok; else cat ${OBJECTDIR}/_ext/1472/PicasoSGC.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o: ../Timer-PWM-Gruppio.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.ok ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o ../Timer-PWM-Gruppio.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION) -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d -o ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o ../Timer-PWM-Gruppio.c   > ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.ok ; fi 
	@touch ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d 
	
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d > ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.tmp ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.ok; else cat ${OBJECTDIR}/_ext/1472/Timer-PWM-Gruppio.o.err; exit 1; fi
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/IGruppioV2.X.${IMAGE_TYPE}.elf: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/IGruppioV2.X.${IMAGE_TYPE}.elf ${OBJECTFILES}        -Wl,--defsym=__MPLAB_BUILD=1,--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-L"../C:/Program Files (x86)/Microchip/MPLAB C32/lib",-L"../C:/Program Files (x86)/Microchip/MPLAB C32/pic32mx/lib",-Map="${DISTDIR}/IGruppioV2.X.${IMAGE_TYPE}.map" 
else
dist/${CND_CONF}/${IMAGE_TYPE}/IGruppioV2.X.${IMAGE_TYPE}.elf: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/IGruppioV2.X.${IMAGE_TYPE}.elf ${OBJECTFILES}        -Wl,--defsym=__MPLAB_BUILD=1,--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-L"../C:/Program Files (x86)/Microchip/MPLAB C32/lib",-L"../C:/Program Files (x86)/Microchip/MPLAB C32/pic32mx/lib",-Map="${DISTDIR}/IGruppioV2.X.${IMAGE_TYPE}.map"
	${MP_CC_DIR}/pic32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/IGruppioV2.X.${IMAGE_TYPE}.elf  
endif


# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
