set(EXTERNAL_MICROPYTHON_DIR "${PROJECT_DIR}/external/micropython")
set(EXTERNAL_MICROPYTHON_BUILD_DIR "${PROJECT_DIR}/external/micropython/ports/ric/build-ric2")
set(EXTERNAL_MICROPYTHON_PORT_DIR, "${PROJECT_DIR}/external/micropython/ports/ric")
set(MICROPYTHON_PORT_DIR "${COMPONENT_DIR}/ports/ric")
set(MICROPYTHON_BOARD_DIR "${COMPONENT_DIR}/ports/ric/boards/ric2")

idf_component_register(
                SRCS 
                  "${EXTERNAL_MICROPYTHON_DIR}/py/argcheck.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/asmbase.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/bc.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/binary.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/builtinevex.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/builtinhelp.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/builtinimport.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/compile.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/emitbc.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/emitcommon.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/emitglue.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/formatfloat.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/frozenmod.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/gc.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/lexer.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/malloc.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/map.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/modbuiltins.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/modgc.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/modmicropython.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/modstruct.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/modthread.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/moduerrno.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/mpprint.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/mpstate.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/mpz.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/nativeglue.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/nlr.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/nlrsetjmp.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/obj.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objarray.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objbool.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objboundmeth.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objcell.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objclosure.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objcomplex.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objdict.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objenumerate.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objexcept.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objfilter.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objfloat.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objfun.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objgenerator.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objgetitemiter.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objint.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objint_mpz.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objlist.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objmap.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objmodule.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objnone.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objobject.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objpolyiter.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objproperty.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objrange.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objreversed.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objset.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objsingleton.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objslice.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objstr.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objstrunicode.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objtuple.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objtype.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/objzip.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/opmethods.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/parse.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/parsenum.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/parsenumbase.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/persistentcode.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/profile.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/qstr.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/reader.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/repl.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/runtime.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/runtime_utils.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/scope.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/scheduler.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/sequence.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/smallint.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/stream.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/stackctrl.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/unicode.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/vm.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/vstr.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/py/warning.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/lib/mp-readline/readline.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/lib/timeutils/timeutils.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/lib/utils/interrupt_char.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/extmod/utime_mphal.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/extmod/vfs.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/extmod/vfs_reader.c"
                  "${EXTERNAL_MICROPYTHON_DIR}/lib/utils/pyexec.c"
                  "${MICROPYTHON_PORT_DIR}/gccollect.c"
                  "${MICROPYTHON_PORT_DIR}/help.c"
                  "${MICROPYTHON_PORT_DIR}/mphalport.c"
                  "${MICROPYTHON_PORT_DIR}/mpthreadport.c"
                  "${MICROPYTHON_PORT_DIR}/modutime.c"
                  "cppif/Micropython.cpp"
                  "${EXTERNAL_MICROPYTHON_BUILD_DIR}/frozen_content.c"
                INCLUDE_DIRS
                  "."
                  ${EXTERNAL_MICROPYTHON_DIR}
                  ${EXTERNAL_MICROPYTHON_DIR}/py
                  ${MICROPYTHON_PORT_DIR}
                  ${MICROPYTHON_BOARD_DIR}
                  cppif
                  RingBuffer
                REQUIRES 
                  )

set( CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DMICROPY_ESP_IDF_4 -Wno-override-init -Wno-implicit-fallthrough -I${EXTERNAL_MICROPYTHON_BUILD_DIR}" )
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DMICROPY_ESP_IDF_4 -I${EXTERNAL_MICROPYTHON_BUILD_DIR}" )

add_custom_command(OUTPUT "${EXTERNAL_MICROPYTHON_BUILD_DIR}/frozen_content.c"
    COMMAND echo "------------- Building Micropython externally ---------------"
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${COMPONENT_DIR}/ports/ric ${EXTERNAL_MICROPYTHON_DIR}/ports/ric
    COMMAND cd ${EXTERNAL_MICROPYTHON_DIR}/ports/ric
    COMMAND make BOARD=ric2 GENERATIONPHASE=y USER_C_MODULES=${EXTERNAL_MICROPYTHON_DIR}/ports/ric/cmodules
    DEPENDS 
      ${MICROPYTHON_PORT_DIR}/mpconfigport.h
)

add_custom_target(generate_frozen ALL
    DEPENDS "${EXTERNAL_MICROPYTHON_BUILD_DIR}/frozen_content.c")

