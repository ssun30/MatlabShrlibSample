function str = longString
    buflen = calllib('shrlibsample', 'createLongStr', 0, '');
    aa = char(ones(1,buflen+1))
    ptr = libpointer('cstring', aa);
    get(ptr)
    [iok, str] = calllib('shrlibsample', 'createLongStr', buflen, ptr);
    if iok ~= 0
        error('This is an error message');
    end
    get(ptr)
    warning(['the pointer value is ',  ptr.Value])
end