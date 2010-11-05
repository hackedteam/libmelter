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
	${OBJECTDIR}/trunk/IOOperation.o \
	${OBJECTDIR}/trunk/Mangler.o \
	${OBJECTDIR}/trunk/Chunk.o \
	${OBJECTDIR}/trunk/IOComplete.o \
	${OBJECTDIR}/trunk/IOManager.o \
	${OBJECTDIR}/trunk/main.o \
	${OBJECTDIR}/trunk/IOBuffer.o \
	${OBJECTDIR}/trunk/BufferObserver.o \
	${OBJECTDIR}/trunk/IOAppend.o \
	${OBJECTDIR}/trunk/Melter.o \
	${OBJECTDIR}/trunk/IOFlush.o

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

${OBJECTDIR}/trunk/IOOperation.o: trunk/IOOperation.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/IOOperation.o trunk/IOOperation.cc

${OBJECTDIR}/trunk/Mangler.o: trunk/Mangler.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/Mangler.o trunk/Mangler.cc

${OBJECTDIR}/trunk/Chunk.o: trunk/Chunk.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/Chunk.o trunk/Chunk.cc

${OBJECTDIR}/trunk/IOComplete.o: trunk/IOComplete.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/IOComplete.o trunk/IOComplete.cc

${OBJECTDIR}/trunk/IOManager.o: trunk/IOManager.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/IOManager.o trunk/IOManager.cc

${OBJECTDIR}/trunk/main.o: trunk/main.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/main.o trunk/main.cc

${OBJECTDIR}/trunk/IOBuffer.o: trunk/IOBuffer.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/IOBuffer.o trunk/IOBuffer.cc

${OBJECTDIR}/trunk/BufferObserver.o: trunk/BufferObserver.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/BufferObserver.o trunk/BufferObserver.cc

${OBJECTDIR}/trunk/IOAppend.o: trunk/IOAppend.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/IOAppend.o trunk/IOAppend.cc

${OBJECTDIR}/trunk/Melter.o: trunk/Melter.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/Melter.o trunk/Melter.cc

${OBJECTDIR}/trunk/IOFlush.o: trunk/IOFlush.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	${RM} $@.d
	$(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/IOFlush.o trunk/IOFlush.cc

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/trunk/tests/BufferDescriptorTest.o ${TESTDIR}/trunk/tests/ChunkTest.o ${TESTDIR}/trunk/tests/IOBufferTest.o ${TESTDIR}/trunk/tests/IOManagerTest.o ${TESTDIR}/trunk/tests/ManglerTest.o ${TESTDIR}/trunk/tests/MelterTest.o ${TESTDIR}/trunk/tests/ParserTest.o ${TESTDIR}/trunk/tests/main.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -L/usr/local/lib -lgtest -lpthread -lgmock -L/usr/local/lib -lcppunit -lcrypto 


${TESTDIR}/trunk/tests/BufferDescriptorTest.o: trunk/tests/BufferDescriptorTest.cc 
	${MKDIR} -p ${TESTDIR}/trunk/tests
	${RM} $@.d
	$(COMPILE.cc) -g -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/trunk/tests/BufferDescriptorTest.o trunk/tests/BufferDescriptorTest.cc


${TESTDIR}/trunk/tests/ChunkTest.o: trunk/tests/ChunkTest.cc 
	${MKDIR} -p ${TESTDIR}/trunk/tests
	${RM} $@.d
	$(COMPILE.cc) -g -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/trunk/tests/ChunkTest.o trunk/tests/ChunkTest.cc


${TESTDIR}/trunk/tests/IOBufferTest.o: trunk/tests/IOBufferTest.cc 
	${MKDIR} -p ${TESTDIR}/trunk/tests
	${RM} $@.d
	$(COMPILE.cc) -g -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/trunk/tests/IOBufferTest.o trunk/tests/IOBufferTest.cc


${TESTDIR}/trunk/tests/IOManagerTest.o: trunk/tests/IOManagerTest.cc 
	${MKDIR} -p ${TESTDIR}/trunk/tests
	${RM} $@.d
	$(COMPILE.cc) -g -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/trunk/tests/IOManagerTest.o trunk/tests/IOManagerTest.cc


${TESTDIR}/trunk/tests/ManglerTest.o: trunk/tests/ManglerTest.cc 
	${MKDIR} -p ${TESTDIR}/trunk/tests
	${RM} $@.d
	$(COMPILE.cc) -g -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/trunk/tests/ManglerTest.o trunk/tests/ManglerTest.cc


${TESTDIR}/trunk/tests/MelterTest.o: trunk/tests/MelterTest.cc 
	${MKDIR} -p ${TESTDIR}/trunk/tests
	${RM} $@.d
	$(COMPILE.cc) -g -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/trunk/tests/MelterTest.o trunk/tests/MelterTest.cc


${TESTDIR}/trunk/tests/ParserTest.o: trunk/tests/ParserTest.cc 
	${MKDIR} -p ${TESTDIR}/trunk/tests
	${RM} $@.d
	$(COMPILE.cc) -g -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/trunk/tests/ParserTest.o trunk/tests/ParserTest.cc


${TESTDIR}/trunk/tests/main.o: trunk/tests/main.cc 
	${MKDIR} -p ${TESTDIR}/trunk/tests
	${RM} $@.d
	$(COMPILE.cc) -g -Itrunk -I/usr/local/include -I/usr/local/include -I. -MMD -MP -MF $@.d -o ${TESTDIR}/trunk/tests/main.o trunk/tests/main.cc


${OBJECTDIR}/trunk/IOOperation_nomain.o: ${OBJECTDIR}/trunk/IOOperation.o trunk/IOOperation.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	@NMOUTPUT=`${NM} ${OBJECTDIR}/trunk/IOOperation.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/IOOperation_nomain.o trunk/IOOperation.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/trunk/IOOperation.o ${OBJECTDIR}/trunk/IOOperation_nomain.o;\
	fi

${OBJECTDIR}/trunk/Mangler_nomain.o: ${OBJECTDIR}/trunk/Mangler.o trunk/Mangler.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	@NMOUTPUT=`${NM} ${OBJECTDIR}/trunk/Mangler.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/Mangler_nomain.o trunk/Mangler.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/trunk/Mangler.o ${OBJECTDIR}/trunk/Mangler_nomain.o;\
	fi

${OBJECTDIR}/trunk/Chunk_nomain.o: ${OBJECTDIR}/trunk/Chunk.o trunk/Chunk.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	@NMOUTPUT=`${NM} ${OBJECTDIR}/trunk/Chunk.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/Chunk_nomain.o trunk/Chunk.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/trunk/Chunk.o ${OBJECTDIR}/trunk/Chunk_nomain.o;\
	fi

${OBJECTDIR}/trunk/IOComplete_nomain.o: ${OBJECTDIR}/trunk/IOComplete.o trunk/IOComplete.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	@NMOUTPUT=`${NM} ${OBJECTDIR}/trunk/IOComplete.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/IOComplete_nomain.o trunk/IOComplete.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/trunk/IOComplete.o ${OBJECTDIR}/trunk/IOComplete_nomain.o;\
	fi

${OBJECTDIR}/trunk/IOManager_nomain.o: ${OBJECTDIR}/trunk/IOManager.o trunk/IOManager.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	@NMOUTPUT=`${NM} ${OBJECTDIR}/trunk/IOManager.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/IOManager_nomain.o trunk/IOManager.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/trunk/IOManager.o ${OBJECTDIR}/trunk/IOManager_nomain.o;\
	fi

${OBJECTDIR}/trunk/main_nomain.o: ${OBJECTDIR}/trunk/main.o trunk/main.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	@NMOUTPUT=`${NM} ${OBJECTDIR}/trunk/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/main_nomain.o trunk/main.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/trunk/main.o ${OBJECTDIR}/trunk/main_nomain.o;\
	fi

${OBJECTDIR}/trunk/IOBuffer_nomain.o: ${OBJECTDIR}/trunk/IOBuffer.o trunk/IOBuffer.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	@NMOUTPUT=`${NM} ${OBJECTDIR}/trunk/IOBuffer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/IOBuffer_nomain.o trunk/IOBuffer.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/trunk/IOBuffer.o ${OBJECTDIR}/trunk/IOBuffer_nomain.o;\
	fi

${OBJECTDIR}/trunk/BufferObserver_nomain.o: ${OBJECTDIR}/trunk/BufferObserver.o trunk/BufferObserver.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	@NMOUTPUT=`${NM} ${OBJECTDIR}/trunk/BufferObserver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/BufferObserver_nomain.o trunk/BufferObserver.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/trunk/BufferObserver.o ${OBJECTDIR}/trunk/BufferObserver_nomain.o;\
	fi

${OBJECTDIR}/trunk/IOAppend_nomain.o: ${OBJECTDIR}/trunk/IOAppend.o trunk/IOAppend.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	@NMOUTPUT=`${NM} ${OBJECTDIR}/trunk/IOAppend.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/IOAppend_nomain.o trunk/IOAppend.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/trunk/IOAppend.o ${OBJECTDIR}/trunk/IOAppend_nomain.o;\
	fi

${OBJECTDIR}/trunk/Melter_nomain.o: ${OBJECTDIR}/trunk/Melter.o trunk/Melter.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	@NMOUTPUT=`${NM} ${OBJECTDIR}/trunk/Melter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/Melter_nomain.o trunk/Melter.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/trunk/Melter.o ${OBJECTDIR}/trunk/Melter_nomain.o;\
	fi

${OBJECTDIR}/trunk/IOFlush_nomain.o: ${OBJECTDIR}/trunk/IOFlush.o trunk/IOFlush.cc 
	${MKDIR} -p ${OBJECTDIR}/trunk
	@NMOUTPUT=`${NM} ${OBJECTDIR}/trunk/IOFlush.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I/usr/local/include -I. -fPIC  -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/trunk/IOFlush_nomain.o trunk/IOFlush.cc;\
	else  \
	    ${CP} ${OBJECTDIR}/trunk/IOFlush.o ${OBJECTDIR}/trunk/IOFlush_nomain.o;\
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
