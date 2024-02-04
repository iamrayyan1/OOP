  #include <iostream>

  void twoSum(int nums[], int size, int target, int result[2]) 
  {
      int left = 0;
      int right = size - 1;

      while (left < right) 
      {
          int sum = nums[left] + nums[right];

          if (sum == target) 
          {
              result[0] = left;
              result[1] = right;
              return;
          } else if (sum < target) 
          {
              left++;
          } else
          {
              right--;
          }
      }
      result[0] = result[1] = -1;
  }

  int main() 
  {

      int size;
      std::cout << "Enter the size of the array: ";
      std::cin >> size;

      int nums[size];
      std::cout << "Enter the elements of the array: ";
      for (int i = 0; i < size; ++i) 
      {
          std::cin >> nums[i];
      }

      int target;
      std::cout << "Enter the target sum: ";
      std::cin >> target;

      int result[2];
      twoSum(nums, size, target, result);

      std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl;

      return 0;
  }
