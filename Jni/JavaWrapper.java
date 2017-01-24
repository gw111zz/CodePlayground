class JavaWrapper {

    static {
        System.loadLibrary("JavaWrapper");
    }

    public static native int getInt();
    public static native String getString();

    public static void printInt() {
        System.out.println("Int: " + getInt());
    }

    public static void printString() {
        System.out.println("String: " + getString());
    }

    public static void main(String[] args) {
        
        printInt();
        printString();
        System.out.println("Done");

    }
}
