int linearSearch(char element) {
    char symbols[7] = {'I','V','X','L','C','D','M'};
    int values[7]  = { 1 , 5 ,10 ,50 ,100,500,1000};

    for (int i = 0; i < 7; i++) {
        if (symbols[i] == element)
            return values[i];
    }
    return 0;
}

int romanToInt(char *s) {
    int sum = 0;
    int size = strlen(s);

    for (int i = 0; i < size - 1; i++) {
        int curr = linearSearch(s[i]);
        int next = linearSearch(s[i + 1]);

        if (curr < next)
            sum -= curr;
        else
            sum += curr;
    }

    // add last character
    sum += linearSearch(s[size - 1]);

    return sum;
}
