// Inserting a key on a B-tree in Java

import java.util.*;
import java.io.*;

public class BTree {

  private int T;

  public class Node {
    int n;
    String key[] = new String[2 * T - 1];
   String marks[] = new String[2 * T - 1];
    Node child[] = new Node[2 * T];
    boolean leaf = true;

    public int Find(String k) {
      for (int i = 0; i < this.n; i++) {
        if (this.key[i].compareTo(k) == 0) { 
          return i;
        }
      }
      return -1;
    };
  }

  public BTree(int t) {
    T = t;
    root = new Node();
    root.n = 0;
    root.leaf = true;
  }

  private static Node root;

  // Search the key
  private Node Search(Node x, String key) {
    int i = 0;
    if (x == null)
      return x;
    for (i = 0; i < x.n; i++) {
      if (key.compareTo(x.key[i]) < 0) { 
        break;
      }
      if (key.compareTo(x.key[i]) == 0) {
	
        return x;
      }
    }
    if (x.leaf) {
      return null;
    } else {
      return Search(x.child[i], key);
    }
  }


 // Search the key
  private static Node Search1(Node x, String key) {
    int i = 0;
    if (x == null)
{ System.out.println("Empty");
      return x;
}
    for (i = 0; i < x.n; i++) {
      if (key.compareTo(x.key[i]) < 0) { 
        break;
      }
      if (key.compareTo(x.key[i]) == 0) {
	System.out.println("Search found");
System.out.println("Roll No.:"+x.key[i]);
System.out.println("Marks :"+x.marks[i]);
        return x;
      }
    }
    if (x.leaf) {
System.out.println("Search Absent");
      return null;
    } else {
      return Search1(x.child[i], key);
    }
  }




  // Split function
  private void Split(Node x, int pos, Node y) {
    Node z = new Node();
    z.leaf = y.leaf;
    z.n = T - 1;
    for (int j = 0; j < T - 1; j++) {
      z.key[j] = y.key[j + T];
z.marks[j] = y.marks[j + T];
    }
    if (!y.leaf) {
      for (int j = 0; j < T; j++) {
        z.child[j] = y.child[j + T];
      }
    }
    y.n = T - 1;
    for (int j = x.n; j >= pos + 1; j--) {
      x.child[j + 1] = x.child[j];
    }
    x.child[pos + 1] = z;

    for (int j = x.n - 1; j >= pos; j--) {
      x.key[j + 1] = x.key[j];
x.marks[j + 1] = x.marks[j];
    }
    x.key[pos] = y.key[T - 1];
x.marks[pos] = y.marks[T - 1];
    x.n = x.n + 1;
  }

  // Insert the key
  public void Insert(final String key,final String marks) {
    Node r = root;
    if (r.n == 2 * T - 1) {
      Node s = new Node();
      root = s;
      s.leaf = false;
      s.n = 0;
      s.child[0] = r;
      Split(s, 0, r);
      _Insert(s, key,marks);
    } else {
      _Insert(r, key,marks);
    }
  }

  // Insert the node
  final private void _Insert(Node x, String k, String m) {

    if (x.leaf) {
      int i = 0;
      for (i = x.n - 1; i >= 0 && k.compareTo(x.key[i]) < 0; i--) { 
        x.key[i + 1] = x.key[i];
	x.marks[i + 1] = x.marks[i];
      }
      x.key[i + 1] = k;
x.marks[i + 1] = m;
      x.n = x.n + 1;
    } else {
      int i = 0;
      for (i = x.n - 1; i >= 0 && k.compareTo(x.key[i]) < 0; i--) {
      }
      ;
      i++;
      Node tmp = x.child[i];
      if (tmp.n == 2 * T - 1) {
        Split(x, i, tmp);
        if (k.compareTo(x.key[i]) > 0) {
          i++;
        }
      }
      _Insert(x.child[i], k, m);
    }

  }

  public void Show() {
    Show(root);
  }

  private void Remove(Node x, String key) {
    int pos = x.Find(key);
    if (pos != -1) {
      if (x.leaf) {
        int i = 0;
        for (i = 0; i < x.n && key.compareTo(x.key[i]) != 0; i++) { 
        }
        ;
        for (; i < x.n; i++) {
          if (i != 2 * T - 2) {
            x.key[i] = x.key[i + 1];
x.marks[i] = x.marks[i + 1];
          }
        }
        x.n--;
        return;
      }
      if (!x.leaf) {

        Node pred = x.child[pos];
        String predKey = "0";
String predmarks = "0";
        if (pred.n >= T) {
          for (;;) {
            if (pred.leaf) {
              System.out.println(pred.n);
              predKey = pred.key[pred.n - 1];
predmarks = pred.marks[pred.n - 1];
              break;
            } else {
              pred = pred.child[pred.n];
            }
          }
          Remove(pred, predKey);
          x.key[pos] = predKey;
x.marks[pos] = predmarks;
          return;
        }

        Node nextNode = x.child[pos + 1];
        if (nextNode.n >= T) {
          String nextKey = nextNode.key[0];
String nextmarks = nextNode.marks[0];
          if (!nextNode.leaf) {
            nextNode = nextNode.child[0];
            for (;;) {
              if (nextNode.leaf) {
                nextKey = nextNode.key[nextNode.n - 1];
nextmarks = nextNode.marks[nextNode.n - 1];
                break;
              } else {
                nextNode = nextNode.child[nextNode.n];
              }
            }
          }
          Remove(nextNode, nextKey);
          x.key[pos] = nextKey;
x.marks[pos] = nextmarks;
          return;
        }

        int temp = pred.n + 1;
        pred.key[pred.n++] = x.key[pos];
pred.marks[pred.n++] = x.marks[pos];
        for (int i = 0, j = pred.n; i < nextNode.n; i++) {
          pred.key[j++] = nextNode.key[i];
pred.marks[j++] = nextNode.marks[i];
          pred.n++;
        }
        for (int i = 0; i < nextNode.n + 1; i++) {
          pred.child[temp++] = nextNode.child[i];
        }

        x.child[pos] = pred;
        for (int i = pos; i < x.n; i++) {
          if (i != 2 * T - 2) {
            x.key[i] = x.key[i + 1];
 x.marks[i] = x.marks[i + 1];
          }
        }
        for (int i = pos + 1; i < x.n + 1; i++) {
          if (i != 2 * T - 1) {
            x.child[i] = x.child[i + 1];
          }
        }
        x.n--;
        if (x.n == 0) {
          if (x == root) {
            root = x.child[0];
          }
          x = x.child[0];
        }
        Remove(pred, key);
        return;
      }
    } else {
      for (pos = 0; pos < x.n; pos++) {
        if (x.key[pos].compareTo(key) > 0) { 
          break;
        }
      }
      Node tmp = x.child[pos];
      if (tmp.n >= T) {
        Remove(tmp, key);
        return;
      }
      if (true) {
        Node nb = null;
        String devider = "-1";

        if (pos != x.n && x.child[pos + 1].n >= T) {
          devider = x.key[pos];
          nb = x.child[pos + 1];
          x.key[pos] = nb.key[0];
x.marks[pos] = nb.marks[0];
          tmp.key[tmp.n++] = devider;
tmp.marks[tmp.n++] = devider;
          tmp.child[tmp.n] = nb.child[0];
          for (int i = 1; i < nb.n; i++) {
            nb.key[i - 1] = nb.key[i];
nb.marks[i - 1] = nb.marks[i];
          }
          for (int i = 1; i <= nb.n; i++) {
            nb.child[i - 1] = nb.child[i];
          }
          nb.n--;
          Remove(tmp, key);
          return;
        } else if (pos != 0 && x.child[pos - 1].n >= T) {

          devider = x.key[pos - 1];
          nb = x.child[pos - 1];
          x.key[pos - 1] = nb.key[nb.n - 1];
x.marks[pos - 1] = nb.marks[nb.n - 1];
          Node child = nb.child[nb.n];
          nb.n--;

          for (int i = tmp.n; i > 0; i--) {
            tmp.key[i] = tmp.key[i - 1];
tmp.marks[i] = tmp.marks[i - 1];
          }
          tmp.key[0] = devider;
tmp.marks[0] = devider;
          for (int i = tmp.n + 1; i > 0; i--) {
            tmp.child[i] = tmp.child[i - 1];
          }
          tmp.child[0] = child;
          tmp.n++;
          Remove(tmp, key);
          return;
        } else {
          Node lt = null;
          Node rt = null;
          boolean last = false;
          if (pos != x.n) {
            devider = x.key[pos];
            lt = x.child[pos];
            rt = x.child[pos + 1];
          } else {
            devider = x.key[pos - 1];
            rt = x.child[pos];
            lt = x.child[pos - 1];
            last = true;
            pos--;
          }
          for (int i = pos; i < x.n - 1; i++) {
            x.key[i] = x.key[i + 1];
x.marks[i] = x.marks[i + 1];
          }
          for (int i = pos + 1; i < x.n; i++) {
            x.child[i] = x.child[i + 1];
          }
          x.n--;
          lt.key[lt.n++] = devider;
  lt.marks[lt.n++] = devider;

          for (int i = 0, j = lt.n; i < rt.n + 1; i++, j++) {
            if (i < rt.n) {
              lt.key[j] = rt.key[i];
lt.marks[j] = rt.marks[i];
            }
            lt.child[j] = rt.child[i];
          }
          lt.n += rt.n;
          if (x.n == 0) {
            if (x == root) {
              root = x.child[0];
            }
            x = x.child[0];
          }
          Remove(lt, key);
          return;
        }
      }
    }
  }

  public void Remove(String key) {
    Node x = Search(root, key);
    if (x == null) {
      return;
    }
    Remove(root, key);
  }

  public void Task(String a, String b) {
    Stack<String> st = new Stack<>();
    FindKeys(a, b, root, st);
    while (st.isEmpty() == false) {
      this.Remove(root, st.pop());
    }
  }

  private void FindKeys(String a, String b, Node x, Stack<String> st) {
    int i = 0;
    for (i = 0; i < x.n && x.key[i].compareTo(b) < 0; i++) { 
      if (x.key[i].compareTo(a) > 0) {
        st.push(x.key[i]);
      }
    }
    if (!x.leaf) {
      for (int j = 0; j < i + 1; j++) {
        FindKeys(a, b, x.child[j], st);
      }
    }
  }

  public boolean Contain(String k) {
    if (this.Search(root, k) != null) {
      return true;
    } else {
      return false;
    }
  }

  // Show the node
  private void Show(Node x) {
    assert (x == null);
    for (int i = 0; i < x.n; i++) {
      System.out.print(x.key[i] + "\t"+x.marks[i]+"\n");
    }
    if (!x.leaf) {
      for (int i = 0; i < x.n + 1; i++) {
        Show(x.child[i]);
      }
    }
  }

  public static void main(String[] args)throws IOException {
    BTree b = new BTree(3);
    
Scanner sc = new Scanner(System.in);
Scanner sc1 = new Scanner(System.in);
Scanner myReader = new Scanner(new File("asn4a.txt"));
 ArrayList <String> temp = new ArrayList <String>();
   
  while (myReader.hasNextLine()) {
	        String data = myReader.nextLine();
	        //System.out.println(data);
	for (String retval: data.split("\t")){
	        //System.out.println(retval);
	        temp.add(retval);
	        }
	
b.Insert(temp.get(0),temp.get(1));
	temp.clear();
		
} 
 myReader.close();

    b.Show();
String x;
String y;
int c;

do
{
    	System.out.println("\n1.Display");
    	System.out.println("2.Insert");
    	System.out.println("3.Delete");
	System.out.println("4.Search");
    	System.out.println("0.Exit");
    	System.out.println("Choice: ");
    	c = sc.nextInt();
    	
    	switch(c)
    	{
    	case 1:
    		 b.Show();
    		break;
    	case 2:
    		System.out.println("Enter Roll No. :");
    		 x= sc1.nextLine();
		System.out.println("Enter Marks :");
    		 y= sc1.nextLine();
    		b.Insert(x, y);
		System.out.println("\n");
    		break;
    	case 3:
    		System.out.println("What no to delete? ");
    		x= sc1.nextLine();
    		 b.Remove(x);
		System.out.println("\nDeleted\n");
    		break;
	case 4:
		System.out.println("Enter Search Item: ");
		x= sc1.nextLine();
		Node x1 = Search1(root, x);
		break;
		
    	case 0:
    		break;
	default:
	System.out.println("Input error");
}
}while(c!=0);

    System.out.println();
  }
}