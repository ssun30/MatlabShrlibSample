function loadShrlib
    if ~libisloaded(ct)
        loadlibrary('shrlibsample', 'shrlibsample.h', ...
                    'addheader', 'shrhelp');
    end
    disp('Matlab Shrlib Sample is Ready for Use');
end