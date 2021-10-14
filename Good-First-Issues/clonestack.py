def clonestack(self, st, cloned):
    count = 0

    # Reverse the order of the values in source stack
    while count != len(st)-1:

        top = st.pop()
        while count != len(st):
            cloned.append(st.pop())

        st.append(top)
        while len(cloned):
            st.append(cloned.pop())

        count += 1

    # Pop the values from source and push into destination stack
    while len(st):
        cloned.append(st.pop())
