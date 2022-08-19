function str = longString
    buflen = calllib('shrlibsample', 'createLongStr', 0, '');
    aa = char(zeros(1,buflen));
    ptr = libpointer('cstring', aa);
    [iok, str] = calllib('shrlibsample', 'createLongStr', buflen, ptr);
    if iok ~= 1
        error('This is an error message');
    end
end