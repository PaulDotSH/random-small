// C/C++
char nrs[100];
sprintf(nrs, "%d_%d\"", i,c);
char req[] = "curl \"https://subdomain.m.pipedream.net/?test=";
strcat(req,nrs);
system(req); 
