using System.Collections;

namespace ConsoleApp1
{
    public class LinkedListNode
    {
        public LinkedListNode(object value)
        {
            this.Value = value;
        }

        public object Value { get; private set; }

        public LinkedListNode Next { get; internal set; }
        public LinkedListNode Prev { get; internal set; }
    }

    public class LinkedList : IEnumerable
    {
        public LinkedListNode First { get; private set; }
        public LinkedListNode Last { get; private set; }

        public LinkedListNode AddLast(object node)
        {
            var newNode = new LinkedListNode(node);
            if (First == null)
            {
                First = newNode;
                Last = First;
            }
            else
            {
                Last.Next = newNode;
                Last = newNode;
            }
            return newNode;
        }

        public IEnumerator GetEnumerator()
        {
            LinkedListNode current = First;
            while (current != null)
            {
                yield return current.Value;
                current = current.Next;
            }
        }
        internal class Program
        {
            static void Main(string[] args)
            {
                //Console.WriteLine("Hello, World!");


            }
        }
    }
}