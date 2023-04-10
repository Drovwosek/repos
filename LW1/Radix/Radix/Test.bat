@echo off

set PROGRAM = "%~1"

rem Simple test
%PROGRAM% 2 10 101 > %TEMP%\output.txt
fc SimpleTest.txt %OUT% > nul 

echo Simple Test passed

rem Zero value test
%PROGRAM% 10 2 0 > %TEMP%\output.txt
fc ZeroValueTest.txt %TEMP%\output.txt > nul

echo Zero value test passed

rem Zero Negative value test
%PROGRAM% 10 2 -0 > %TEMP%\output.txt
fc ZeroNegativeValueTest.txt %TEMP%\output.txt > nul 
echo Zero negative value test passed

rem Invalid value test
%PROGRAM% 2 10 10* > %TEMP%\output.txt
fc InvalidValueTest.txt %TEMP%\output.txt > nul
echo Invalid value test passed

rem Invalid source notation test
%PROGRAM% 2 10 1D > %TEMP%\output.txt
fc InvalidSourceNotationTest.txt %TEMP%\output.txt > nul 
echo Invalid source notation test passed

rem Max positive border test
%PROGRAM% 10 16 2147483647 > %TEMP%\output.txt
fc MaxPositiveBorderTest.txt %TEMP%\output.txt > nul 
echo Max positive border test passed

rem Max positive number +1 test
%PROGRAM% 10 16 2147483648 > %TEMP%\output.txt
fc MaxPositiveNumber+1Test.txt %TEMP%\output.txt > nul 
echo Max positive number test +1 passed

rem Max negative border test
%PROGRAM% 10 16 -2147483647 > %TEMP%\output.txt
fc MaxNegativeBorderTest.txt %TEMP%\output.txt > nul 
echo Max negative border test passed

rem Max negative number -1 test
%PROGRAM% 10 16 -2147483648 > %TEMP%\output.txt           	
fc MaxnegativeNumber-1Test.txt %TEMP%\output.txt > nul 
echo Max negative number -1 test passed

rem Invalid radix test
%PROGRAM% 1 16 1 > %TEMP%\output.txt
fc InvalidRadixTest.txt %TEMP%\output.txt > nul 

echo Invalid radix test passed

echo tests passed succsessfuly
exit /B 0

:err
echo Test failed
exit /B 1