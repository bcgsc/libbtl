/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 4.0.1
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package btllib;

public class SeqWriter {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected SeqWriter(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(SeqWriter obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  @SuppressWarnings("deprecation")
  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        btllibJNI.delete_SeqWriter(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public SeqWriter(String sink, SeqWriter.Format format, boolean append) {
    this(btllibJNI.new_SeqWriter__SWIG_0(sink, format.swigValue(), append), true);
  }

  public SeqWriter(String sink, SeqWriter.Format format) {
    this(btllibJNI.new_SeqWriter__SWIG_1(sink, format.swigValue()), true);
  }

  public void close() {
    btllibJNI.SeqWriter_close(swigCPtr, this);
  }

  public void write(String name, String comment, String seq, String qual) {
    btllibJNI.SeqWriter_write(swigCPtr, this, name, comment, seq, qual);
  }

  public final static class Format {
    public final static SeqWriter.Format FASTA = new SeqWriter.Format("FASTA");
    public final static SeqWriter.Format FASTQ = new SeqWriter.Format("FASTQ");

    public final int swigValue() {
      return swigValue;
    }

    public String toString() {
      return swigName;
    }

    public static Format swigToEnum(int swigValue) {
      if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
        return swigValues[swigValue];
      for (int i = 0; i < swigValues.length; i++)
        if (swigValues[i].swigValue == swigValue)
          return swigValues[i];
      throw new IllegalArgumentException("No enum " + Format.class + " with value " + swigValue);
    }

    private Format(String swigName) {
      this.swigName = swigName;
      this.swigValue = swigNext++;
    }

    private Format(String swigName, int swigValue) {
      this.swigName = swigName;
      this.swigValue = swigValue;
      swigNext = swigValue+1;
    }

    private Format(String swigName, Format swigEnum) {
      this.swigName = swigName;
      this.swigValue = swigEnum.swigValue;
      swigNext = this.swigValue+1;
    }

    private static Format[] swigValues = { FASTA, FASTQ };
    private static int swigNext = 0;
    private final int swigValue;
    private final String swigName;
  }

}