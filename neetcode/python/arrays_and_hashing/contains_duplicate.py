def hasDuplicate(nums: list[int]) -> bool:
    occurrences = set()
    for num in nums:
        if num in occurrences:
            return True
        else:
            occurrences.add(num)
    return False



def main():
    nums = input().split()
    print(hasDuplicate(nums))



if __name__ == "__main__":
    main()