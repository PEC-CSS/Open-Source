{
  "nbformat": 4,
  "nbformat_minor": 0,
  "metadata": {
    "colab": {
      "name": "Intro-sort.ipynb",
      "provenance": [],
      "collapsed_sections": []
    },
    "kernelspec": {
      "name": "python3",
      "display_name": "Python 3"
    },
    "language_info": {
      "name": "python"
    }
  },
  "cells": [
    {
      "cell_type": "markdown",
      "metadata": {
        "id": "HsQUzO3aKjJR"
      },
      "source": [
        "**INTRO SORT ALGORITHM**"
      ]
    },
    {
      "cell_type": "markdown",
      "metadata": {
        "id": "7GAgxi5zKnVW"
      },
      "source": [
        "**OVERVIEW :**\n",
        "\n",
        "Introsort is an efficient <a href=\"https://www.techiedelight.com/in-place-vs-out-of-place-algorithms/\" rel=\"noopener noreferrer\">in-place sorting algorithm</a>, which usually beats all other sorting algorithms in terms of performance. Due to its high performance, it is used in several standard library sort functions, including some <a href=\"https://www.techiedelight.com/sort-vector-cpp/\" rel=\"noopener noreferrer\">C++ sort implementations</a>\n",
        "\n",
        "\n"
      ]
    },
    {
      "cell_type": "markdown",
      "metadata": {
        "id": "fcDkEPPZL1Cc"
      },
      "source": [
        "**IMPLEMENTATION** :  \n",
        "\n",
        "<p>Introsort is a hybrid of <a href=\"https://www.techiedelight.com/quicksort/\" rel=\"noopener noreferrer\">Quicksort</a> and <a href=\"https://www.techiedelight.com/heap-sort-place-place-implementation-c-c/\" rel=\"noopener noreferrer\">heapsort algorithm</a>. A <a href=\"https://www.techiedelight.com/hybrid-quicksort/\" rel=\"noopener noreferrer\">hybrid algorithm</a> combines two or more other algorithms that solve the same problem such that the resulting algorithm is better than the individual algorithms. Introsort begins with Quicksort and switches to heapsort when the recursion depth exceeds a level based on (the logarithm of) the total number of elements being sorted. When the total number of elements is below some threshold, introsort can switch to a non-recursive sorting algorithm such as <a href=\"https://www.techiedelight.com/insertion-sort-iterative-recursive/\" rel=\"noopener noreferrer\">insertion sort</a> that performs fewer swaps, comparisons or other operations on such small arrays.</p>"
      ]
    },
    {
      "cell_type": "markdown",
      "metadata": {
        "id": "pVDF_61HQAnW"
      },
      "source": [
        "**ALGORITHM AND PSEUDOCODE**\n",
        "\n",
        "procedure sort(A : array):\n",
        "\n",
        "    let maxdepth = ⌊log(length(A))⌋ × 2\n",
        "    introSort(A, maxdepth)\n",
        "\n",
        "procedure introsort(A, maxdepth):\n",
        "\n",
        "    n ← length(A)\n",
        "    if n < 20:\n",
        "        insertionsort(A)\n",
        "    else if maxdepth = 0:\n",
        "        heapsort(A)\n",
        "    else:\n",
        "        p ← partition(A)  // the pivot is selected using median of 3\n",
        "        introsort(A[0:p], maxdepth - 1)\n",
        "        introsort(A[p+1:n], maxdepth - 1)\n",
        "\n"
      ]
    },
    {
      "cell_type": "code",
      "metadata": {
        "id": "mVEMe-IsS9Ni"
      },
      "source": [
        "#Python Implementation of Intro-Sort\n",
        "\n",
        "def introsort(alist):\n",
        "    maxdepth = (len(alist).bit_length() - 1)*2\n",
        "    introsort_helper(alist, 0, len(alist), maxdepth)\n",
        " \n",
        "def introsort_helper(alist, start, end, maxdepth):\n",
        "    if end - start <= 1:\n",
        "        return\n",
        "    elif maxdepth == 0:\n",
        "        heapsort(alist, start, end)\n",
        "    else:\n",
        "        p = partition(alist, start, end)\n",
        "        introsort_helper(alist, start, p + 1, maxdepth - 1)\n",
        "        introsort_helper(alist, p + 1, end, maxdepth - 1)\n",
        " \n",
        "def partition(alist, start, end):\n",
        "    pivot = alist[start]\n",
        "    i = start - 1\n",
        "    j = end\n",
        " \n",
        "    while True:\n",
        "        i = i + 1\n",
        "        while alist[i] < pivot:\n",
        "            i = i + 1\n",
        "        j = j - 1\n",
        "        while alist[j] > pivot:\n",
        "            j = j - 1\n",
        " \n",
        "        if i >= j:\n",
        "            return j\n",
        " \n",
        "        swap(alist, i, j)\n",
        " \n",
        "def swap(alist, i, j):\n",
        "    alist[i], alist[j] = alist[j], alist[i]\n",
        " \n",
        "def heapsort(alist, start, end):\n",
        "    build_max_heap(alist, start, end)\n",
        "    for i in range(end - 1, start, -1):\n",
        "        swap(alist, start, i)\n",
        "        max_heapify(alist, index=0, start=start, end=i)\n",
        " \n",
        "def build_max_heap(alist, start, end):\n",
        "    def parent(i):\n",
        "        return (i - 1)//2\n",
        "    length = end - start\n",
        "    index = parent(length - 1)\n",
        "    while index >= 0:\n",
        "        max_heapify(alist, index, start, end)\n",
        "        index = index - 1\n",
        " \n",
        "def max_heapify(alist, index, start, end):\n",
        "    def left(i):\n",
        "        return 2*i + 1\n",
        "    def right(i):\n",
        "        return 2*i + 2\n",
        " \n",
        "    size = end - start\n",
        "    l = left(index)\n",
        "    r = right(index)\n",
        "    if (l < size and alist[start + l] > alist[start + index]):\n",
        "        largest = l\n",
        "    else:\n",
        "        largest = index\n",
        "    if (r < size and alist[start + r] > alist[start + largest]):\n",
        "        largest = r\n",
        "    if largest != index:\n",
        "        swap(alist, start + largest, start + index)\n",
        "        max_heapify(alist, largest, start, end)\n",
        " \n",
        " \n",
        "alist = input('Enter the list of numbers: ').split()\n",
        "alist = [int(x) for x in alist]\n",
        "introsort(alist)\n",
        "print('Sorted list: ', end='')\n",
        "print(alist)"
      ],
      "execution_count": null,
      "outputs": []
    }
  ]
}