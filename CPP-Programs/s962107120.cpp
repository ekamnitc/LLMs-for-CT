
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifndef U_L_LONG
typedef unsigned long long U_L_LONG;
#endif
#ifndef L_LONG
typedef long long L_LONG;
#endif

//	https://tenka1-2018-beginner.contest.atcoder.jp/assignments

static void A_Measure();

int main()
{
	A_Measure();

	fflush(stdout);
	return 0;
}

static void A_Measure()
{
	char szS[4] = { 0 };

	scanf(" %s", szS);

	if (strlen(szS) == 3) {
		char tmp = szS[0];
		szS[0] = szS[2];
		szS[2] = tmp;
	}
	printf("%s\n", szS);
}
