package alda.linear;

/**
 * Created by lukas on 2018-01-17.
 *  @author Henrik
 */
public interface AldaList<E> extends Iterable<E> {
    public void add(E element);

    public void add(int index, E element);

    public E remove(int index);

    public boolean remove(E element);

    public E get(int index);

    public boolean contains(E element);

    public int indexOf(E element);

    public void clear();

    public int size();
}
