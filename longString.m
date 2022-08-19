function str = longString
    aa = zeros(1:buflen);
    ptr = libpointer('cstring', aa);
    [iok, str] = calllib('shrlibsample', 'createLongStr', ptr);
    if iok ~= 1
        error('This is an error message');
    end
end