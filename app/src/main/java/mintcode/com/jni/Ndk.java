package mintcode.com.jni;

/**
 * Created by mark on 16-5-25.
 */
public class Ndk {

    private String name;

    static {
        System.loadLibrary("Mintcode");
    }

    public Ndk(String name) {
        this.name = name;
    }

    public native String convert(String name);


    public native void swapValue(String first,String second);


    public native void sort(int[] array);
}
