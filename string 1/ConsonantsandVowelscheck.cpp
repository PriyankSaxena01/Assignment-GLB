void checkString(string s) {
    int v = 0;
    int c = 0;

    // Your code here
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        continue;
        else if(s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ||s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u')
        v++;
        else c++;
    }

    if (v > c)
        cout << "Yes";
    else if (c > v)
        cout << "No";
    else
        cout << "Same";

    cout << endl;
}
