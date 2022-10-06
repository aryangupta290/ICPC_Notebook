/**
 * Author: Noam527
 * Date: 2019-04-24
 * License: CC0
 * Source: folklore
 * Description:
 * Status: tested
 */
int power(long long x, unsigned int y, int p){
	int res = 1;
	x = x % p;
	if (x == 0)
		return 0;
	while (y > 0){
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}
