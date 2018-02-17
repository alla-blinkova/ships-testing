set testname TAT_Test

# Clear
foreach file [glob -nocomplain work/*.* test/${testname}*.* test/*.log *.obj *.exe *.mpr *.lst *.txt] {file delete $file}

# Atsgen
exec ../../bin/atsgen -m mpr/test.mpr -config config.xml -o work/${testname}.tcl -mf -tt -state -nia -asn1

# CGTC
exec tclsh ../../cgtc/cgtc.tcl -ats work/${testname}.tcl -log -inst -break -time -o test

# Compile
set srcfiles "test/${testname}.c test/${testname}data.c test/wrapper.c ../../cgtc/mprlog.c ../../cgtc/txtlog.c ../../cgtc/testkern.c"
catch {eval exec "cl.exe /I ../../cgtc /D WIN32 /D _DEBUG /D _CONSOLE /D TAT_TIME_SUPPORT /D TAT_INSTANCE_SUPPORT /D _MBCS $srcfiles /link /OUT:${testname}.exe"} res

# Pun
exec $testname