class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def detectloop(self, head) -> bool:
      # this technique called fast-slow pointer
        try:
            slow = head
            fast = head.next
            while slow is not fast:
                slow = slow.next
                fast = fast.next.next
            return True
        except:
            return False


# Test
test = Solution()

# Doesn't contain a loop
node_a = ListNode(1)
node_b = ListNode(2)
head = node_a
head.next = node_b
print(test.detectloop(head))

# make a loop
node_b.next = node_a
print(test.detectloop(head))
