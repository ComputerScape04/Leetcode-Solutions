class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        int i = 0, j = n-1;

        while(i < j) {
            // get the horizontal distance between the lines
            int x_distance = j - i;

            // take the smaller line amongst the two
            int y_distance = min(height[i], height[j]);

            // multiply them to get the area of water between them
            maxArea = max(maxArea, x_distance * y_distance);

            // preserve the longer line
            if (height[i] < height[j]) 
                i++;
            else
                j--;
        }

        return maxArea;
    }
};
