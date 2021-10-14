import java.util.HashMap;
import java.util.Map;

public class MRUCache {

    public static void main(String[] args) {
        MRUCache cache = new MRUCache(5);
        cache.put(1, 1);
        cache.put(2, 2);
        cache.put(3, 3);
        cache.put(4, 4);
        cache.put(5, 5);
        cache.put(6, 6);

        cache.get(2);
        cache.put(7, 7);
    }

    class MRUNode {
        int key;
        int value;

        MRUNode pre;
        MRUNode next;

        public MRUNode(int key, int value) {
            this.key = key;
            this.value = value;
        }

        public MRUNode() {
        }

        public String toString() {
            return printForward();
        }

        public String printForward() {
            if (next != null && next != tail) {
                return value + " -> " + next.printForward();
            } else {
                return ((Integer) value).toString();
            }
        }
    }

    private Map<Integer, MRUNode> cache = new HashMap<>();
    private int count;
    private final int capacity;
    private MRUNode head;
    private MRUNode tail;

    /**
     * It will create an MRU cache with just two dummy nodes, head and tail linked to each other
     */
    public MRUCache(int capacity) {
        this.count = 0;
        this.capacity = capacity;

        head = new MRUNode();
        head.pre = null;

        tail = new MRUNode();
        tail.next = null;

        head.next = tail;
        tail.pre = head;
    }

    /**
     * New node is added always at the tail
     */
    private void addNode(MRUNode node) {
        // Step 1: Link the node's left and right pointers
        node.next = tail;
        node.pre = tail.pre;

        // Step 2: Update next and head
        // Change the right node's backward link first, otherwise you'll loose it.
        tail.pre.next = node;
        tail.pre = node;
    }

    /**
     * Remove an existing node from the linked list.
     */
    private void removeNode(MRUNode node) {
        MRUNode pre = node.pre;
        MRUNode next = node.next;

        pre.next = next;
        next.pre = pre;
    }

    /**
     * Move certain node in between to the head.
     */
    private void moveToTail(MRUNode node) {
        this.removeNode(node);
        this.addNode(node);
    }

    /**
     * pop the current tail.
     */
    private MRUNode popTail() {
        MRUNode res = tail.pre;
        this.removeNode(res);
        return res;
    }

    public int get(int key) {
        MRUNode node = cache.get(key);

        // move the accessed node to the tail;
        this.moveToTail(node);

        System.out.println("Cache after get(" + key + ") is " + head.next.toString());

        return node.value;
    }

    public void put(int key, int value) {
        MRUNode node = cache.get(key);

        // It means, it is a new key
        if (node == null) {
            // Generate a new node
            MRUNode newNode = new MRUNode(key, value);

            // Put it in the cache
            this.cache.put(key, newNode);

            // If size has over shot capacity, drop one MRU item
            if (count == capacity) {
                MRUNode tail = this.popTail();
                this.cache.remove(tail.key);
                count--;
            }

            // Add the item at the tail (since it's an MRU cache)
            this.addNode(newNode);

            // Increase the size
            count++;
        } else { // This value already exists. Update it and push it to the end to make it MRU
            node.value = value;
            this.moveToTail(node);
        }

        System.out.println("Cache after put(" + key + "," + value + ") is " + head.next.toString());
    }
}
