from setuptools import setup
with open('README.md', 'r') as f:
    long_description = f.read()
setup(
  name = 'dropy',
  packages = ['dropy'],
  version = '0.1.0',
  license='MIT',
  description = 'A simple package for a simple drone simulator created in unity',
  long_description=long_description,
  long_description_content_type='text/markdown',
  author = 'Aousnik Gupta',
  author_email = 'guptaaousnik@gmail.com',
  url = 'https://github.com/gittygupta/dropy',
  download_url = 'https://github.com/gittygupta/dropy/archive/v0.1.0.tar.gz',
  keywords = ['simulator', 'python', 'unity', 'flight', 'control', 'NN', 'training', 'utility'],
  install_requires=[
          'validators',
          'pillow',
          'pywinauto',
          'pyautogui'
      ],
  classifiers=[
    'Development Status :: 3 - Alpha',
    'Intended Audience :: Developers',
    'Topic :: Software Development :: Build Tools',
    'License :: OSI Approved :: MIT License',
    'Programming Language :: Python :: 3',
    'Programming Language :: Python :: 3.6',
    'Programming Language :: Python :: 3.7',
    'Programming Language :: Python :: 3.8',
  ],
)
