PROGRAM eratosthenes(output);
CONST
    max = 1000;
    
VAR
    sieve : ARRAY [..max] OF BOOLEAN;
    i, j, limit, prime, factor : INTEGER;
    
BEGIN
    limit := max DIV 2;
    sieve[] := FALSE;
    
    FOR i := 2 TO max DO
        sieve[i] := TRUE;

    prime := 1;
    
    REPEAT
        prime := prime + 1;
        WHILE NOT sieve[prime] DO
            prime := prime + 1;
            
        factor := 2*prime;
        
        WHILE factor <= max DO BEGIN
            sieve[factor] := FALSE;
            factor := factor + prime;
        END
    UNTIL prime > limit;
    
    writeln('Sieve of Eratosthenes');
    writeln;
    
    i := 1;
    REPEAT
        FOR j :=  TO 9 DO BEGIN
            prime := i + j;
            IF sieve[prime] THEN
                write(prime:3)
            ELSE
                write('   ');
        END;
        writeln;
        
        i := i + 2
    UNTIL i > max
END.
