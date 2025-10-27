from typing import List

class Solution:
    def recoverOrder(self, order: List[int], friends: List[int]) -> List[int]:
        friends_set = set(friends) # 新しい集合を作る
        result = []
        
        for part_id in order:
            if part_id in friends_set:
                result.append(part_id)
        
        return result

# Test the solution
if __name__ == "__main__":
    solution = Solution()
    
    # Example test case
    order = [3, 1, 4, 2, 5]
    friends = [1, 3, 5]
    print(solution.recoverOrder(order, friends))