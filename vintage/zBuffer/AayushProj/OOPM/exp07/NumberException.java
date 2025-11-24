public class NumberException extends Exception
{
    public NumberException(String message) {
        super(message);
    }
    @Override
    public String toString() {
        return "NumberException: " + getMessage();
    }
}
