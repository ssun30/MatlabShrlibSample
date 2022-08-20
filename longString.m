function str = longString
    buflen = calllib('shrlibsample', 'createLongStr', 0, '');
    aa = repelem('a',buflen)
    ptr = libpointer('string', aa);
    get(ptr)
    [iok, str] = calllib('shrlibsample', 'createLongStr', buflen, ptr);
    if iok ~= 0
        error('This is an error message');
    end
    get(ptr)
    warning(['the pointer value is ',  ptr.Value])
end