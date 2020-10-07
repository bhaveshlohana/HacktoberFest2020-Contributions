{
 "cells": [
  {
   "cell_type": "code",
   "execution_count": 12,
   "metadata": {},
   "outputs": [
    {
     "name": "stdout",
     "output_type": "stream",
     "text": [
      "Using for loop\n",
      "['https://www.google.co.in/', 'http://www.yahoo.com/', 'http://www.linkedin.com/', 'http://www.kuchbhi.kin/\\n']\n",
      "200\n",
      "301\n",
      "200\n",
      "failed to connect\n"
     ]
    }
   ],
   "source": [
    "L = [\"https://www.google.co.in/,http://www.yahoo.com/,http://www.linkedin.com/,http://www.kuchbhi.kin/\\n\"] \n",
    "\n",
    "# Writing to file \n",
    "file1 = open('URLlist.txt', 'w') \n",
    "file1.writelines(L) \n",
    "file1.close() \n",
    "\n",
    "# Opening file \n",
    "file1 = open('URLlist.txt', 'r') \n",
    "count = 0\n",
    "\n",
    "# Using for loop \n",
    "print(\"Using for loop\") \n",
    "for line in file1: \n",
    "\tcount += 1\n",
    "\tx=(line.split(',')) \n",
    "print(x)\n",
    "# Closing files \n",
    "file1.close() \n",
    "\n",
    "#taking url from x and getting the status code\n",
    "import requests\n",
    "for url in x:\n",
    "    try:\n",
    "        r = requests.head(url)\n",
    "        print(r.status_code)\n",
    "    # prints the int of the status code.\n",
    "    except:\n",
    "        print(\"failed to connect\")    \n"
   ]
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  },
  {
   "cell_type": "code",
   "execution_count": null,
   "metadata": {},
   "outputs": [],
   "source": []
  }
 ],
 "metadata": {
  "kernelspec": {
   "display_name": "Python 3",
   "language": "python",
   "name": "python3"
  },
  "language_info": {
   "codemirror_mode": {
    "name": "ipython",
    "version": 3
   },
   "file_extension": ".py",
   "mimetype": "text/x-python",
   "name": "python",
   "nbconvert_exporter": "python",
   "pygments_lexer": "ipython3",
   "version": "3.7.3"
  }
 },
 "nbformat": 4,
 "nbformat_minor": 2
}
