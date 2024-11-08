// Reset field counter b to 0
:S 0b! ;

// Function F: Store input in a, call S to split, print number of fields in b
:F a!S b. ;

// Function P: Store input in a, print "Field" followed by value in a and colon
:P a!`Field `a.`: `;

// Function C: If a equals 1, print "Column 1:" and value in a
:C a1=(`Column 1: `a.)/E ;

// Function D: If a equals 3, print "Column 3:" and value in a
:D a3=(`Column 3: `a.)/E ;

// Function Q: If a equals 2, store it in x and print x
// Used for summing values in column 2
:Q a2=(ax!x.);

// Function R: Call F to get fields, call Q to update sum, print "Sum:" and value in x
:R FQ`Sum: `x. ;

// Function T: If a equals 3 and is greater than 100, print message
:T a3=(a100>(`Column 3>100`))/E ;

// Function U: Call F to get fields, then T to check column 3
:U FT ;

// Function W: Call F to get fields, print "Formatted:" and value in a
:W F`Formatted: `a. ;

// Function Y: Call F to get fields, print "Line:" and value in a
:Y F`Line: `a. ;

// Function B: Main menu
// 1. Print menu options with newlines (/N)
// 2. Read key (/K), subtract 48 to convert ASCII to number, store in n
// 3. Check n against values 1-6 and call appropriate function
:B`Commands:`/N`1-Print cols 1,3`/N`2-Running sum`/N`3-Check col 3`/N`4-Format out`/N`5-Print line`/N`6-Field count`/N
/K48-n!n1=(P)/En2=(R)/En3=(U)/En4=(W)/En5=(Y)/En6=(F);

// Function M: Main entry point
// Initialize x to 0 (for sums), then call menu B
:M 0x!B ;
