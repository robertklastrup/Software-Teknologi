function xq = quantize(x, N)
    V = max(abs(x));
    delta = 2*V / 2^N;
    xq = delta * round(x/delta);
end