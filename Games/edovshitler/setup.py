from distutils.core import setup
setup(
  name = 'edovshitler',
  packages = ['edovshitler'],
  version = '0.1.2',
  license='MIT',
  description ='Simple python game built with pygame. Have fun!',
  author = 'Edoardo Ottavianelli',
  author_email = 'edoardott@gmail.com',
  url = 'https://github.com/edoardottt/edovshitler',
  download_url = 'https://github.com/edoardottt/edovshitler/archive/v0.1.2.tar.gz',
  keywords = ['python game','pygame'],
  install_requires=[
          'pygame',

      ],
  classifiers=[
    'Development Status :: 3 - Alpha',
    'Intended Audience :: Developers',
    'Topic :: Software Development :: Build Tools',
    'License :: OSI Approved :: MIT License',
    'Programming Language :: Python :: 3',
    'Programming Language :: Python :: 3.4',
    'Programming Language :: Python :: 3.5',
    'Programming Language :: Python :: 3.6',
  ],
)