set name=%1
del %1
set post=.bak
rename %name%%post% %1
