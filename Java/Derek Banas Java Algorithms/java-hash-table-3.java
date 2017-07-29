import java.util.Scanner;


class HashFunction3 {
    WordList[] arr;
    int size;
    public String[][] elementsToAdd = {
			{ "ace", "Very good" },
			{ "act", "Take action" },
			{ "add", "Join (something) to something else" },
			{ "age", "Grow old" },
			{ "ago", "Before the present" },
			{ "aid", "Help, assist, or support" },
			{ "aim", "Point or direct" },
			{ "air", "Invisible gaseous substance" },
			{ "all", "Used to refer to the whole quantity" },
			{ "amp",
					"Unit of measure for the strength of an electrical current" },
			{ "and", "Used to connect words" }, { "ant", "A small insect" },
			{ "any", "Used to refer to one or some of a thing" },
			{ "ape", "A large primate" },
			{ "apt", "Appropriate or suitable in the circumstances" },
			{ "arc", "A part of the circumference of a curve" },
			{ "are", "Unit of measure, equal to 100 square meters" },
			{ "ark", "The ship built by Noah" },
			{ "arm", "Two upper limbs of the human body" },
			{ "art", "Expression or application of human creative skill" },
			{ "ash", "Powdery residue left after the burning" },
			{ "ask", "Say something in order to obtain information" },
			{ "asp", "Small southern European viper" },
			{ "ass", "Hoofed mammal" },
			{ "ate", "To put (food) into the mouth and swallow it" },
			{ "atm", "Unit of pressure" },
			{ "awe", "A feeling of reverential respect" },
			{ "axe", "Edge tool with a heavy bladed head" },
			{ "aye", "An affirmative answer" } };


    public int stringHash(String word) {
        int hashKey = 0;

        for(int i=0; i<word.length(); ++i) {
            int charCode = word.charAt(i) - 96;
            int hKVTemp = hashKey;

            hashKey = (hashKey * 27 + charCode) % size;

            System.out.println("Hash Key Value " + hKVTemp + " * 27 + Character Code " + charCode + " % size " + size + " = " + hashKey);
        }

        System.out.println();

        return hashKey;
    }

    HashFunction3(int size) {
        this.size = size;
        this.arr = new WordList[size];

        for(int i=0; i<size; ++i) {
            this.arr[i] = new WordList();
        }

        addTheArray(this.elementsToAdd);
    }

    public void insert(Word newWord) {
        String wordToHash = newWord.theWord;
        int hashKey = stringHash(wordToHash);

        this.arr[hashKey].insert(newWord, hashKey);
    }


    public Word find(String tofind) {
        int hashKey = stringHash(tofind);
        Word word = this.arr[hashKey].find(hashKey, tofind);

        return word;
    }

    public void addTheArray(String[][] elements) {
        for(int i=0; i < elements.length; ++i) {
            String word = elements[i][0];
            String definition = elements[i][1];

            Word newWord = new Word(word, definition);
            insert(newWord);
        }
    }

    public void display() {
        for(int i=0; i<this.size; ++i) {
            System.out.println("Array Index " + i);
            this.arr[i].display();
        }
    }
}


class Word {

    public String theWord;
    public String definition;

    public int key;

    public Word next;

    Word(String theWord, String definition) {
        this.theWord = theWord;
        this.definition = definition;
    }

    public String toString() {
        return this.theWord + ": " + this.definition;
    }
}


class WordList {

    public Word firstWord = null;

    public void insert(Word newWord, int hashKey) {
        Word previous = null;
        Word current = firstWord;

        newWord.key = hashKey;

        while(current != null && newWord.key > current.key) {
            previous = current;
            current = current.next;
        }

        if(previous == null)
            firstWord = newWord;
        else
            previous.next = newWord;
        newWord.next = current;
    }

    public void display() {
        Word current = firstWord;

        while(current != null) {
            System.out.println(current);
            current = current.next;
        }
    }

    public Word find(int hashKey, String wordToFind) {
        Word current = firstWord;

        while(current != null && current.key <= hashKey) {
            if(current.theWord.equals(wordToFind))
                return current;
            current = current.next;
        }

        return null;
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        HashFunction3 hashtable = new HashFunction3(11);

        String wordLookUp = "a";

        while(!wordLookUp.equalsIgnoreCase("x")) {
            System.out.println(": ");

            wordLookUp = input.nextLine();

            System.out.println(hashtable.find(wordLookUp));
        }

        hashtable.display();
    }
}