function arrayValues = getArray(length)
    % GET.X  Get the mole fractions of all species.
    % moleFractions = tp.X
    %
    % :param tp:
    %     Instance of class :mat:func:`ThermoPhase` (or another
    %     object that derives from ThermoPhase)
    % :return:
    %     Vector of species mole fractions for input phase. If
    %     no output argument is specified, a bar plot is produced.
    %
    xx = zeros(1, length);
    ptr = libpointer('doublePtr', xx);
    get(ptr)
    [iok, val] = calllib('shrlibsample', 'createDoubleArray', length, ptr);
    if iok ~= 0
        error('This is an error message');
    end
    get(ptr)
    arrayValues = ptr.Value;
end
