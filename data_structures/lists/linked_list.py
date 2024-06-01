class Node:
    def __init__(self, value, next=None):
        self.value = value
        self.next = next

    def __str__(self):
        return str(self.value)

    def __lt__(self, other):
        return self.value < other.value

    def __gt__(self, other):
        return self.value > other.value
        

class LinkedList:
    def __init__(self, arr, head=None):
        if not arr:
            self.head = head
        else:
            node = Node(arr[-1])
            for i in range(len(arr) - 2, -1, -1):
                node = Node(arr[i], node)

            self.head = node

    def __str__(self):
        string = ""
        head = self.head
        while head:
            string += "{} -> ".format(head.value)
            head = head.next
        
        return string + str(None)


# O(n), O(1)
def search(head, x):
    while head:
        if head.value == x:
            return head
        
        head = head.next

    return None


# O(1), O(1)
def insert(head, node):
    node.next = head
    head = node
    return head


# O(n), O(1)
def append(head, node):
    while head.next:
        head = head.next

    head.next = node
    node.next = None


# O(n), O(1)
def delete(head, node):
    while head and head.value != node.value:
        prev = head
        head = head.next

    if head:
        prev.next = head.next
        del head
        return node
    else:
        return None


# O(n), O(1)
def minimum(head):
    smallest = head
    while head:
        if head < smallest:
            smallest = head
        
        head = head.next
    
    return smallest


# O(n), O(1)
def maximum(head):
    largest = head
    while head:
        if head > largest:
            largest = head

        head = head.next

    return largest


# O(n), O(1)
def successor(head, x):
    node = search(head, x)
    return node.next if node else None


# O(n), O(1)
def predecessor(head, x):
    prev = None
    while head:
        if head.value == x:
            return prev

        prev = head
        head = head.next

    return None


# O(n), O(1)
def reverse(head, stop):
    prev, curr = None, head

    while curr != stop:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next

    return prev


if __name__ == "__main__":
    linkedlist = LinkedList([-3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
    
    print(search(linkedlist.head, -3))
    print(search(linkedlist.head, 9))

    linkedlist.head = insert(linkedlist.head, Node(-4))
    append(linkedlist.head, Node(10))
    delete(linkedlist.head, Node(0))
    delete(linkedlist.head, Node(100))
    print(linkedlist)

    print(minimum(linkedlist.head))
    print(maximum(linkedlist.head))

    print(successor(linkedlist.head, 5))
    print(successor(linkedlist.head, 10))
    print(successor(linkedlist.head, 100))

    print(predecessor(linkedlist.head, 5))
    print(predecessor(linkedlist.head, -4))
    print(predecessor(linkedlist.head, 100))

    print(LinkedList(None, reverse(linkedlist.head, None)))