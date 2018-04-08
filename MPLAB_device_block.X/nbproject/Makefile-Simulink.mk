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
ifeq "$(wildcard nbproject/Makefile-local-Simulink.mk)" "nbproject/Makefile-local-Simulink.mk"
include nbproject/Makefile-local-Simulink.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=Simulink
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_device_block.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_device_block.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

ifdef SUB_IMAGE_ADDRESS
SUB_IMAGE_ADDRESS_COMMAND=--image-address $(SUB_IMAGE_ADDRESS)
else
SUB_IMAGE_ADDRESS_COMMAND=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=MPLAB_device_block.c MPLAB_device_block_main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/MPLAB_device_block.o ${OBJECTDIR}/MPLAB_device_block_main.o
POSSIBLE_DEPFILES=${OBJECTDIR}/MPLAB_device_block.o.d ${OBJECTDIR}/MPLAB_device_block_main.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/MPLAB_device_block.o ${OBJECTDIR}/MPLAB_device_block_main.o

# Source Files
SOURCEFILES=MPLAB_device_block.c MPLAB_device_block_main.c


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
	${MAKE}  -f nbproject/Makefile-Simulink.mk dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_device_block.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=33EP128MC502
MP_LINKER_FILE_OPTION=,--script=p33EP128MC502.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/MPLAB_device_block.o: MPLAB_device_block.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MPLAB_device_block.o.d 
	@${RM} ${OBJECTDIR}/MPLAB_device_block.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MPLAB_device_block.c  -o ${OBJECTDIR}/MPLAB_device_block.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MPLAB_device_block.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -I"MPLAB_device_block.X" -I"." -I".." -I"C:/PROGRA~2/MICROC~1/xc16/v1.34/include" -I"C:/PROGRA~2/MICROC~1/xc16/v1.34/support/dsPIC33E/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.34/support/generic/h" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/ert" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/extern/include" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/simulink/include" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/MPLAB_device_block.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MPLAB_device_block_main.o: MPLAB_device_block_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MPLAB_device_block_main.o.d 
	@${RM} ${OBJECTDIR}/MPLAB_device_block_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MPLAB_device_block_main.c  -o ${OBJECTDIR}/MPLAB_device_block_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MPLAB_device_block_main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -I"MPLAB_device_block.X" -I"." -I".." -I"C:/PROGRA~2/MICROC~1/xc16/v1.34/include" -I"C:/PROGRA~2/MICROC~1/xc16/v1.34/support/dsPIC33E/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.34/support/generic/h" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/ert" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/extern/include" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/simulink/include" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/MPLAB_device_block_main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/MPLAB_device_block.o: MPLAB_device_block.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MPLAB_device_block.o.d 
	@${RM} ${OBJECTDIR}/MPLAB_device_block.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MPLAB_device_block.c  -o ${OBJECTDIR}/MPLAB_device_block.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MPLAB_device_block.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -I"MPLAB_device_block.X" -I"." -I".." -I"C:/PROGRA~2/MICROC~1/xc16/v1.34/include" -I"C:/PROGRA~2/MICROC~1/xc16/v1.34/support/dsPIC33E/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.34/support/generic/h" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/ert" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/extern/include" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/simulink/include" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/MPLAB_device_block.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/MPLAB_device_block_main.o: MPLAB_device_block_main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/MPLAB_device_block_main.o.d 
	@${RM} ${OBJECTDIR}/MPLAB_device_block_main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  MPLAB_device_block_main.c  -o ${OBJECTDIR}/MPLAB_device_block_main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/MPLAB_device_block_main.o.d"      -mno-eds-warn  -g -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -O3 -I"MPLAB_device_block.X" -I"." -I".." -I"C:/PROGRA~2/MICROC~1/xc16/v1.34/include" -I"C:/PROGRA~2/MICROC~1/xc16/v1.34/support/dsPIC33E/h" -I"C:/PROGRA~2/MICROC~1/xc16/v1.34/support/generic/h" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/ert" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/extern/include" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/simulink/include" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src/ext_mode/common" -I"C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src/ext_mode/common" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/MPLAB_device_block_main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_device_block.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  C:/PROGRA~2/MICROC~1/xc16/v1.34/lib/libpic30-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.34/lib/libm-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.34/lib/libc-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.34/lib/libq-dsp-elf.a  
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_device_block.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    C:\PROGRA~2\MICROC~1\xc16\v1.34\lib\libpic30-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.34\lib\libm-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.34\lib\libc-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.34\lib\libq-dsp-elf.a  -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x1000:0x101B -mreserve=data@0x101C:0x101D -mreserve=data@0x101E:0x101F -mreserve=data@0x1020:0x1021 -mreserve=data@0x1022:0x1023 -mreserve=data@0x1024:0x1027 -mreserve=data@0x1028:0x104F   -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="MPLAB_device_block.X",--library-path=".",--library-path="..",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.34/include",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.34/support/dsPIC33E/h",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.34/support/generic/h",--library-path="C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/ert",--library-path="C:/Program Files/MATLAB/MATLAB Production Server/R2015a/extern/include",--library-path="C:/Program Files/MATLAB/MATLAB Production Server/R2015a/simulink/include",--library-path="C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src",--library-path="C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src/ext_mode/common",--library-path="C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src/ext_mode/common",--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_device_block.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk  C:/PROGRA~2/MICROC~1/xc16/v1.34/lib/libpic30-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.34/lib/libm-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.34/lib/libc-elf.a C:/PROGRA~2/MICROC~1/xc16/v1.34/lib/libq-dsp-elf.a 
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_device_block.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}    C:\PROGRA~2\MICROC~1\xc16\v1.34\lib\libpic30-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.34\lib\libm-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.34\lib\libc-elf.a C:\PROGRA~2\MICROC~1\xc16\v1.34\lib\libq-dsp-elf.a  -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -DXPRJ_Simulink=$(CND_CONF)  -legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--library-path="MPLAB_device_block.X",--library-path=".",--library-path="..",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.34/include",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.34/support/dsPIC33E/h",--library-path="C:/PROGRA~2/MICROC~1/xc16/v1.34/support/generic/h",--library-path="C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/ert",--library-path="C:/Program Files/MATLAB/MATLAB Production Server/R2015a/extern/include",--library-path="C:/Program Files/MATLAB/MATLAB Production Server/R2015a/simulink/include",--library-path="C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src",--library-path="C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src/ext_mode/common",--library-path="C:/Program Files/MATLAB/MATLAB Production Server/R2015a/rtw/c/src/ext_mode/common",--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/MPLAB_device_block.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Simulink
	${RM} -r dist/Simulink

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
