int number_of_stations(vector<int>& arr, long double dist) {
	int cnt = 0;
	for (int i = 0; i < arr.size() - 1; i++) {
		int station_cnt = (arr[i+1] - arr[i]) / dist;
		// if the above was exactly divisible, we need to exclude one station
		if ((arr[i+1] - arr[i]) == station_cnt * dist)
			station_cnt--;
		cnt += station_cnt;
	}
	return cnt;
}

double minimiseMaxDistance(vector<int> &arr, int k){
	int n = arr.size();
	long double l = 0, h = -1;
	// answer is always going to be within [l, h]
	// where h is the max distance b/w any consecutive gas station
	for (int i = 0; i < n-1; i++)
		h = std::max(h, (long double)(arr[i+1] - arr[i]));
	
	while(h - l > 1e-6) {
		// mid is the distance we consider between any 2 gas station to place a new gas station
		long double mid = (l + h) / 2.0;
		// get the number of stations
		int count = number_of_stations(arr, mid);
		if (count > k)
			l = mid;
		else
			h = mid;
	}

	return h;
}

