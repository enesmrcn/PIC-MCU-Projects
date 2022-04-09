#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/orhanAltinbasak.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/orhanAltinbasak.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS

else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=templete.asm delete.asm 33_portbInterrupt.asm 34_timer0_introduction.asm 35_timer1.asm 36_timer2.asm 37_watchDogTimer.asm 38_sleepMode.asm 39_comparators_LDR.asm 40_referenceVoltage.asm 41_captureMode.asm 43_pwmMode.asm 42_compareMode.asm 44_usart_Transmitter.asm 45_usart_Receiver.asm 46_eeprom.asm templete_c.asm

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/templete.o ${OBJECTDIR}/delete.o ${OBJECTDIR}/33_portbInterrupt.o ${OBJECTDIR}/34_timer0_introduction.o ${OBJECTDIR}/35_timer1.o ${OBJECTDIR}/36_timer2.o ${OBJECTDIR}/37_watchDogTimer.o ${OBJECTDIR}/38_sleepMode.o ${OBJECTDIR}/39_comparators_LDR.o ${OBJECTDIR}/40_referenceVoltage.o ${OBJECTDIR}/41_captureMode.o ${OBJECTDIR}/43_pwmMode.o ${OBJECTDIR}/42_compareMode.o ${OBJECTDIR}/44_usart_Transmitter.o ${OBJECTDIR}/45_usart_Receiver.o ${OBJECTDIR}/46_eeprom.o ${OBJECTDIR}/templete_c.o
POSSIBLE_DEPFILES=${OBJECTDIR}/templete.o.d ${OBJECTDIR}/delete.o.d ${OBJECTDIR}/33_portbInterrupt.o.d ${OBJECTDIR}/34_timer0_introduction.o.d ${OBJECTDIR}/35_timer1.o.d ${OBJECTDIR}/36_timer2.o.d ${OBJECTDIR}/37_watchDogTimer.o.d ${OBJECTDIR}/38_sleepMode.o.d ${OBJECTDIR}/39_comparators_LDR.o.d ${OBJECTDIR}/40_referenceVoltage.o.d ${OBJECTDIR}/41_captureMode.o.d ${OBJECTDIR}/43_pwmMode.o.d ${OBJECTDIR}/42_compareMode.o.d ${OBJECTDIR}/44_usart_Transmitter.o.d ${OBJECTDIR}/45_usart_Receiver.o.d ${OBJECTDIR}/46_eeprom.o.d ${OBJECTDIR}/templete_c.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/templete.o ${OBJECTDIR}/delete.o ${OBJECTDIR}/33_portbInterrupt.o ${OBJECTDIR}/34_timer0_introduction.o ${OBJECTDIR}/35_timer1.o ${OBJECTDIR}/36_timer2.o ${OBJECTDIR}/37_watchDogTimer.o ${OBJECTDIR}/38_sleepMode.o ${OBJECTDIR}/39_comparators_LDR.o ${OBJECTDIR}/40_referenceVoltage.o ${OBJECTDIR}/41_captureMode.o ${OBJECTDIR}/43_pwmMode.o ${OBJECTDIR}/42_compareMode.o ${OBJECTDIR}/44_usart_Transmitter.o ${OBJECTDIR}/45_usart_Receiver.o ${OBJECTDIR}/46_eeprom.o ${OBJECTDIR}/templete_c.o

# Source Files
SOURCEFILES=templete.asm delete.asm 33_portbInterrupt.asm 34_timer0_introduction.asm 35_timer1.asm 36_timer2.asm 37_watchDogTimer.asm 38_sleepMode.asm 39_comparators_LDR.asm 40_referenceVoltage.asm 41_captureMode.asm 43_pwmMode.asm 42_compareMode.asm 44_usart_Transmitter.asm 45_usart_Receiver.asm 46_eeprom.asm templete_c.asm



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/orhanAltinbasak.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16f628a
MP_LINKER_DEBUG_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/templete.o: templete.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/templete.o.d 
	@${RM} ${OBJECTDIR}/templete.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/templete.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/templete.lst\\\" -e\\\"${OBJECTDIR}/templete.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/templete.o\\\" \\\"templete.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/templete.o"
	@${FIXDEPS} "${OBJECTDIR}/templete.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/delete.o: delete.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delete.o.d 
	@${RM} ${OBJECTDIR}/delete.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/delete.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/delete.lst\\\" -e\\\"${OBJECTDIR}/delete.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/delete.o\\\" \\\"delete.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/delete.o"
	@${FIXDEPS} "${OBJECTDIR}/delete.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/33_portbInterrupt.o: 33_portbInterrupt.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/33_portbInterrupt.o.d 
	@${RM} ${OBJECTDIR}/33_portbInterrupt.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/33_portbInterrupt.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/33_portbInterrupt.lst\\\" -e\\\"${OBJECTDIR}/33_portbInterrupt.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/33_portbInterrupt.o\\\" \\\"33_portbInterrupt.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/33_portbInterrupt.o"
	@${FIXDEPS} "${OBJECTDIR}/33_portbInterrupt.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/34_timer0_introduction.o: 34_timer0_introduction.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/34_timer0_introduction.o.d 
	@${RM} ${OBJECTDIR}/34_timer0_introduction.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/34_timer0_introduction.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/34_timer0_introduction.lst\\\" -e\\\"${OBJECTDIR}/34_timer0_introduction.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/34_timer0_introduction.o\\\" \\\"34_timer0_introduction.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/34_timer0_introduction.o"
	@${FIXDEPS} "${OBJECTDIR}/34_timer0_introduction.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/35_timer1.o: 35_timer1.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/35_timer1.o.d 
	@${RM} ${OBJECTDIR}/35_timer1.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/35_timer1.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/35_timer1.lst\\\" -e\\\"${OBJECTDIR}/35_timer1.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/35_timer1.o\\\" \\\"35_timer1.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/35_timer1.o"
	@${FIXDEPS} "${OBJECTDIR}/35_timer1.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/36_timer2.o: 36_timer2.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/36_timer2.o.d 
	@${RM} ${OBJECTDIR}/36_timer2.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/36_timer2.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/36_timer2.lst\\\" -e\\\"${OBJECTDIR}/36_timer2.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/36_timer2.o\\\" \\\"36_timer2.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/36_timer2.o"
	@${FIXDEPS} "${OBJECTDIR}/36_timer2.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/37_watchDogTimer.o: 37_watchDogTimer.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/37_watchDogTimer.o.d 
	@${RM} ${OBJECTDIR}/37_watchDogTimer.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/37_watchDogTimer.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/37_watchDogTimer.lst\\\" -e\\\"${OBJECTDIR}/37_watchDogTimer.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/37_watchDogTimer.o\\\" \\\"37_watchDogTimer.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/37_watchDogTimer.o"
	@${FIXDEPS} "${OBJECTDIR}/37_watchDogTimer.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/38_sleepMode.o: 38_sleepMode.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/38_sleepMode.o.d 
	@${RM} ${OBJECTDIR}/38_sleepMode.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/38_sleepMode.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/38_sleepMode.lst\\\" -e\\\"${OBJECTDIR}/38_sleepMode.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/38_sleepMode.o\\\" \\\"38_sleepMode.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/38_sleepMode.o"
	@${FIXDEPS} "${OBJECTDIR}/38_sleepMode.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/39_comparators_LDR.o: 39_comparators_LDR.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/39_comparators_LDR.o.d 
	@${RM} ${OBJECTDIR}/39_comparators_LDR.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/39_comparators_LDR.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/39_comparators_LDR.lst\\\" -e\\\"${OBJECTDIR}/39_comparators_LDR.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/39_comparators_LDR.o\\\" \\\"39_comparators_LDR.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/39_comparators_LDR.o"
	@${FIXDEPS} "${OBJECTDIR}/39_comparators_LDR.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/40_referenceVoltage.o: 40_referenceVoltage.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/40_referenceVoltage.o.d 
	@${RM} ${OBJECTDIR}/40_referenceVoltage.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/40_referenceVoltage.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/40_referenceVoltage.lst\\\" -e\\\"${OBJECTDIR}/40_referenceVoltage.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/40_referenceVoltage.o\\\" \\\"40_referenceVoltage.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/40_referenceVoltage.o"
	@${FIXDEPS} "${OBJECTDIR}/40_referenceVoltage.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/41_captureMode.o: 41_captureMode.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/41_captureMode.o.d 
	@${RM} ${OBJECTDIR}/41_captureMode.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/41_captureMode.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/41_captureMode.lst\\\" -e\\\"${OBJECTDIR}/41_captureMode.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/41_captureMode.o\\\" \\\"41_captureMode.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/41_captureMode.o"
	@${FIXDEPS} "${OBJECTDIR}/41_captureMode.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/43_pwmMode.o: 43_pwmMode.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/43_pwmMode.o.d 
	@${RM} ${OBJECTDIR}/43_pwmMode.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/43_pwmMode.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/43_pwmMode.lst\\\" -e\\\"${OBJECTDIR}/43_pwmMode.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/43_pwmMode.o\\\" \\\"43_pwmMode.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/43_pwmMode.o"
	@${FIXDEPS} "${OBJECTDIR}/43_pwmMode.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/42_compareMode.o: 42_compareMode.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/42_compareMode.o.d 
	@${RM} ${OBJECTDIR}/42_compareMode.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/42_compareMode.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/42_compareMode.lst\\\" -e\\\"${OBJECTDIR}/42_compareMode.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/42_compareMode.o\\\" \\\"42_compareMode.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/42_compareMode.o"
	@${FIXDEPS} "${OBJECTDIR}/42_compareMode.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/44_usart_Transmitter.o: 44_usart_Transmitter.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/44_usart_Transmitter.o.d 
	@${RM} ${OBJECTDIR}/44_usart_Transmitter.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/44_usart_Transmitter.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/44_usart_Transmitter.lst\\\" -e\\\"${OBJECTDIR}/44_usart_Transmitter.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/44_usart_Transmitter.o\\\" \\\"44_usart_Transmitter.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/44_usart_Transmitter.o"
	@${FIXDEPS} "${OBJECTDIR}/44_usart_Transmitter.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/45_usart_Receiver.o: 45_usart_Receiver.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/45_usart_Receiver.o.d 
	@${RM} ${OBJECTDIR}/45_usart_Receiver.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/45_usart_Receiver.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/45_usart_Receiver.lst\\\" -e\\\"${OBJECTDIR}/45_usart_Receiver.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/45_usart_Receiver.o\\\" \\\"45_usart_Receiver.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/45_usart_Receiver.o"
	@${FIXDEPS} "${OBJECTDIR}/45_usart_Receiver.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/46_eeprom.o: 46_eeprom.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/46_eeprom.o.d 
	@${RM} ${OBJECTDIR}/46_eeprom.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/46_eeprom.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/46_eeprom.lst\\\" -e\\\"${OBJECTDIR}/46_eeprom.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/46_eeprom.o\\\" \\\"46_eeprom.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/46_eeprom.o"
	@${FIXDEPS} "${OBJECTDIR}/46_eeprom.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/templete_c.o: templete_c.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/templete_c.o.d 
	@${RM} ${OBJECTDIR}/templete_c.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/templete_c.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -d__DEBUG -d__MPLAB_DEBUGGER_SIMULATOR=1 -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/templete_c.lst\\\" -e\\\"${OBJECTDIR}/templete_c.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/templete_c.o\\\" \\\"templete_c.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/templete_c.o"
	@${FIXDEPS} "${OBJECTDIR}/templete_c.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
else
${OBJECTDIR}/templete.o: templete.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/templete.o.d 
	@${RM} ${OBJECTDIR}/templete.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/templete.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/templete.lst\\\" -e\\\"${OBJECTDIR}/templete.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/templete.o\\\" \\\"templete.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/templete.o"
	@${FIXDEPS} "${OBJECTDIR}/templete.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/delete.o: delete.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/delete.o.d 
	@${RM} ${OBJECTDIR}/delete.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/delete.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/delete.lst\\\" -e\\\"${OBJECTDIR}/delete.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/delete.o\\\" \\\"delete.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/delete.o"
	@${FIXDEPS} "${OBJECTDIR}/delete.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/33_portbInterrupt.o: 33_portbInterrupt.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/33_portbInterrupt.o.d 
	@${RM} ${OBJECTDIR}/33_portbInterrupt.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/33_portbInterrupt.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/33_portbInterrupt.lst\\\" -e\\\"${OBJECTDIR}/33_portbInterrupt.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/33_portbInterrupt.o\\\" \\\"33_portbInterrupt.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/33_portbInterrupt.o"
	@${FIXDEPS} "${OBJECTDIR}/33_portbInterrupt.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/34_timer0_introduction.o: 34_timer0_introduction.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/34_timer0_introduction.o.d 
	@${RM} ${OBJECTDIR}/34_timer0_introduction.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/34_timer0_introduction.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/34_timer0_introduction.lst\\\" -e\\\"${OBJECTDIR}/34_timer0_introduction.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/34_timer0_introduction.o\\\" \\\"34_timer0_introduction.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/34_timer0_introduction.o"
	@${FIXDEPS} "${OBJECTDIR}/34_timer0_introduction.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/35_timer1.o: 35_timer1.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/35_timer1.o.d 
	@${RM} ${OBJECTDIR}/35_timer1.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/35_timer1.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/35_timer1.lst\\\" -e\\\"${OBJECTDIR}/35_timer1.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/35_timer1.o\\\" \\\"35_timer1.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/35_timer1.o"
	@${FIXDEPS} "${OBJECTDIR}/35_timer1.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/36_timer2.o: 36_timer2.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/36_timer2.o.d 
	@${RM} ${OBJECTDIR}/36_timer2.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/36_timer2.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/36_timer2.lst\\\" -e\\\"${OBJECTDIR}/36_timer2.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/36_timer2.o\\\" \\\"36_timer2.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/36_timer2.o"
	@${FIXDEPS} "${OBJECTDIR}/36_timer2.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/37_watchDogTimer.o: 37_watchDogTimer.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/37_watchDogTimer.o.d 
	@${RM} ${OBJECTDIR}/37_watchDogTimer.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/37_watchDogTimer.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/37_watchDogTimer.lst\\\" -e\\\"${OBJECTDIR}/37_watchDogTimer.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/37_watchDogTimer.o\\\" \\\"37_watchDogTimer.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/37_watchDogTimer.o"
	@${FIXDEPS} "${OBJECTDIR}/37_watchDogTimer.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/38_sleepMode.o: 38_sleepMode.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/38_sleepMode.o.d 
	@${RM} ${OBJECTDIR}/38_sleepMode.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/38_sleepMode.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/38_sleepMode.lst\\\" -e\\\"${OBJECTDIR}/38_sleepMode.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/38_sleepMode.o\\\" \\\"38_sleepMode.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/38_sleepMode.o"
	@${FIXDEPS} "${OBJECTDIR}/38_sleepMode.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/39_comparators_LDR.o: 39_comparators_LDR.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/39_comparators_LDR.o.d 
	@${RM} ${OBJECTDIR}/39_comparators_LDR.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/39_comparators_LDR.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/39_comparators_LDR.lst\\\" -e\\\"${OBJECTDIR}/39_comparators_LDR.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/39_comparators_LDR.o\\\" \\\"39_comparators_LDR.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/39_comparators_LDR.o"
	@${FIXDEPS} "${OBJECTDIR}/39_comparators_LDR.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/40_referenceVoltage.o: 40_referenceVoltage.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/40_referenceVoltage.o.d 
	@${RM} ${OBJECTDIR}/40_referenceVoltage.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/40_referenceVoltage.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/40_referenceVoltage.lst\\\" -e\\\"${OBJECTDIR}/40_referenceVoltage.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/40_referenceVoltage.o\\\" \\\"40_referenceVoltage.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/40_referenceVoltage.o"
	@${FIXDEPS} "${OBJECTDIR}/40_referenceVoltage.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/41_captureMode.o: 41_captureMode.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/41_captureMode.o.d 
	@${RM} ${OBJECTDIR}/41_captureMode.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/41_captureMode.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/41_captureMode.lst\\\" -e\\\"${OBJECTDIR}/41_captureMode.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/41_captureMode.o\\\" \\\"41_captureMode.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/41_captureMode.o"
	@${FIXDEPS} "${OBJECTDIR}/41_captureMode.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/43_pwmMode.o: 43_pwmMode.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/43_pwmMode.o.d 
	@${RM} ${OBJECTDIR}/43_pwmMode.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/43_pwmMode.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/43_pwmMode.lst\\\" -e\\\"${OBJECTDIR}/43_pwmMode.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/43_pwmMode.o\\\" \\\"43_pwmMode.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/43_pwmMode.o"
	@${FIXDEPS} "${OBJECTDIR}/43_pwmMode.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/42_compareMode.o: 42_compareMode.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/42_compareMode.o.d 
	@${RM} ${OBJECTDIR}/42_compareMode.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/42_compareMode.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/42_compareMode.lst\\\" -e\\\"${OBJECTDIR}/42_compareMode.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/42_compareMode.o\\\" \\\"42_compareMode.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/42_compareMode.o"
	@${FIXDEPS} "${OBJECTDIR}/42_compareMode.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/44_usart_Transmitter.o: 44_usart_Transmitter.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/44_usart_Transmitter.o.d 
	@${RM} ${OBJECTDIR}/44_usart_Transmitter.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/44_usart_Transmitter.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/44_usart_Transmitter.lst\\\" -e\\\"${OBJECTDIR}/44_usart_Transmitter.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/44_usart_Transmitter.o\\\" \\\"44_usart_Transmitter.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/44_usart_Transmitter.o"
	@${FIXDEPS} "${OBJECTDIR}/44_usart_Transmitter.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/45_usart_Receiver.o: 45_usart_Receiver.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/45_usart_Receiver.o.d 
	@${RM} ${OBJECTDIR}/45_usart_Receiver.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/45_usart_Receiver.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/45_usart_Receiver.lst\\\" -e\\\"${OBJECTDIR}/45_usart_Receiver.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/45_usart_Receiver.o\\\" \\\"45_usart_Receiver.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/45_usart_Receiver.o"
	@${FIXDEPS} "${OBJECTDIR}/45_usart_Receiver.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/46_eeprom.o: 46_eeprom.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/46_eeprom.o.d 
	@${RM} ${OBJECTDIR}/46_eeprom.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/46_eeprom.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/46_eeprom.lst\\\" -e\\\"${OBJECTDIR}/46_eeprom.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/46_eeprom.o\\\" \\\"46_eeprom.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/46_eeprom.o"
	@${FIXDEPS} "${OBJECTDIR}/46_eeprom.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
${OBJECTDIR}/templete_c.o: templete_c.asm  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/templete_c.o.d 
	@${RM} ${OBJECTDIR}/templete_c.o 
	@${FIXDEPS} dummy.d -e "${OBJECTDIR}/templete_c.err" $(SILENT) -c ${MP_AS} $(MP_EXTRA_AS_PRE) -q -p$(MP_PROCESSOR_OPTION) -u  -l\\\"${OBJECTDIR}/templete_c.lst\\\" -e\\\"${OBJECTDIR}/templete_c.err\\\" $(ASM_OPTIONS)    -o\\\"${OBJECTDIR}/templete_c.o\\\" \\\"templete_c.asm\\\" 
	@${DEP_GEN} -d "${OBJECTDIR}/templete_c.o"
	@${FIXDEPS} "${OBJECTDIR}/templete_c.o.d" $(SILENT) -rsi ${MP_AS_DIR} -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/orhanAltinbasak.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)    -w -x -u_DEBUG -z__ICD2RAM=1 -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"   -z__MPLAB_BUILD=1  -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_SIMULATOR=1 $(MP_LINKER_DEBUG_OPTION) -odist/${CND_CONF}/${IMAGE_TYPE}/orhanAltinbasak.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
else
dist/${CND_CONF}/${IMAGE_TYPE}/orhanAltinbasak.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)    -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"   -z__MPLAB_BUILD=1  -odist/${CND_CONF}/${IMAGE_TYPE}/orhanAltinbasak.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
