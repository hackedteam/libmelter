#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/IOBuffer.o \
	${OBJECTDIR}/IOFlush.o \
	${OBJECTDIR}/IOAppend.o \
	${OBJECTDIR}/Melter.o \
	${OBJECTDIR}/Chunk.o \
	${OBJECTDIR}/IOManager.o \
	${OBJECTDIR}/Mangler.o \
	${OBJECTDIR}/IOComplete.o \
	${OBJECTDIR}/IOOperation.o \
	${OBJECTDIR}/BufferObserver.o

# Test Directory
TESTDIR=build/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk build/Debug/GNU-Linux-x86/tests/TestFiles/f2

build/Debug/GNU-Linux-x86/tests/TestFiles/f2: ${OBJECTFILES}
	${MKDIR} -p build/Debug/GNU-Linux-x86/tests/TestFiles
	${LINK.cc} -shared -o ${TESTDIR}/TestFiles/f2 -fPIC ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/main.o: main.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cc

${OBJECTDIR}/IOBuffer.o: IOBuffer.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IOBuffer.o IOBuffer.cc

${OBJECTDIR}/IOFlush.o: IOFlush.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IOFlush.o IOFlush.cc

${OBJECTDIR}/IOAppend.o: IOAppend.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IOAppend.o IOAppend.cc

${OBJECTDIR}/Melter.o: Melter.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Melter.o Melter.cc

${OBJECTDIR}/Chunk.o: Chunk.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Chunk.o Chunk.cc

${OBJECTDIR}/IOManager.o: IOManager.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IOManager.o IOManager.cc

${OBJECTDIR}/Mangler.o: Mangler.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/Mangler.o Mangler.cc

${OBJECTDIR}/IOComplete.o: IOComplete.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IOComplete.o IOComplete.cc

${OBJECTDIR}/IOOperation.o: IOOperation.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/IOOperation.o IOOperation.cc

${OBJECTDIR}/BufferObserver.o: BufferObserver.cc 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/BufferObserver.o BufferObserver.cc

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/BufferDescriptorTest.o ${TESTDIR}/tests/ChunkTest.o ${TESTDIR}/tests/IOBufferTest.o ${TESTDIR}/tests/IOManagerTest.o ${TESTDIR}/tests/ManglerTest.o ${TESTDIR}/tests/MelterTest.o ${TESTDIR}/tests/ParserTest.o ${TESTDIR}/tests/main.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -L/usr/local/lib -lgtest -lpthread -lgmock -L/usr/local/lib -lcppunit -lcrypto 


${TESTDIR}/tests/BufferDescriptorTest.o: tests/BufferDescriptorTest.cc 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/BufferDescriptorTest.o tests/BufferDescriptorTest.cc


${TESTDIR}/tests/ChunkTest.o: tests/ChunkTest.cc 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/ChunkTest.o tests/ChunkTest.cc


${TESTDIR}/tests/IOBufferTest.o: tests/IOBufferTest.cc 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/IOBufferTest.o tests/IOBufferTest.cc


${TESTDIR}/tests/IOManagerTest.o: tests/IOManagerTest.cc 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/IOManagerTest.o tests/IOManagerTest.cc


${TESTDIR}/tests/ManglerTest.o: tests/ManglerTest.cc 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/ManglerTest.o tests/ManglerTest.cc


${TESTDIR}/tests/MelterTest.o: tests/MelterTest.cc 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/MelterTest.o tests/MelterTest.cc


${TESTDIR}/tests/ParserTest.o: tests/ParserTest.cc 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/ParserTest.o tests/ParserTest.cc


${TESTDIR}/tests/main.o: tests/main.cc 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/main.o tests/main.cc


${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cc 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/IOBuffer_nomain.o: ${OBJECTDIR}/IOBuffer.o IOBuffer.cc 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IOBuffer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/IOBuffer_nomain.o IOBuffer.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/IOBuffer.o ${OBJECTDIR}/IOBuffer_nomain.o;\
	fi

${OBJECTDIR}/IOFlush_nomain.o: ${OBJECTDIR}/IOFlush.o IOFlush.cc 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IOFlush.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/IOFlush_nomain.o IOFlush.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/IOFlush.o ${OBJECTDIR}/IOFlush_nomain.o;\
	fi

${OBJECTDIR}/IOAppend_nomain.o: ${OBJECTDIR}/IOAppend.o IOAppend.cc 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IOAppend.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/IOAppend_nomain.o IOAppend.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/IOAppend.o ${OBJECTDIR}/IOAppend_nomain.o;\
	fi

${OBJECTDIR}/Melter_nomain.o: ${OBJECTDIR}/Melter.o Melter.cc 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Melter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Melter_nomain.o Melter.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/Melter.o ${OBJECTDIR}/Melter_nomain.o;\
	fi

${OBJECTDIR}/Chunk_nomain.o: ${OBJECTDIR}/Chunk.o Chunk.cc 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Chunk.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Chunk_nomain.o Chunk.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/Chunk.o ${OBJECTDIR}/Chunk_nomain.o;\
	fi

${OBJECTDIR}/IOManager_nomain.o: ${OBJECTDIR}/IOManager.o IOManager.cc 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IOManager.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/IOManager_nomain.o IOManager.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/IOManager.o ${OBJECTDIR}/IOManager_nomain.o;\
	fi

${OBJECTDIR}/Mangler_nomain.o: ${OBJECTDIR}/Mangler.o Mangler.cc 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Mangler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Mangler_nomain.o Mangler.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/Mangler.o ${OBJECTDIR}/Mangler_nomain.o;\
	fi

${OBJECTDIR}/IOComplete_nomain.o: ${OBJECTDIR}/IOComplete.o IOComplete.cc 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IOComplete.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/IOComplete_nomain.o IOComplete.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/IOComplete.o ${OBJECTDIR}/IOComplete_nomain.o;\
	fi

${OBJECTDIR}/IOOperation_nomain.o: ${OBJECTDIR}/IOOperation.o IOOperation.cc 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/IOOperation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/IOOperation_nomain.o IOOperation.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/IOOperation.o ${OBJECTDIR}/IOOperation_nomain.o;\
	fi

${OBJECTDIR}/BufferObserver_nomain.o: ${OBJECTDIR}/BufferObserver.o BufferObserver.cc 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/BufferObserver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/BufferObserver_nomain.o BufferObserver.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/BufferObserver.o ${OBJECTDIR}/BufferObserver_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} build/Debug/GNU-Linux-x86/tests/TestFiles/f2

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
