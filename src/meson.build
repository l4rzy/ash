project('ash', ['c'],
    version: '0.1',
    license: 'MIT'
)

c_args = [
    '-O0',
    '-g'
]

sources = files(
    'main.c'
)

subdir('command')

dependencies = [
    dependency('libarchive'),
    dependency('readline')
]

e = executable('ash',
    sources: sources,
    c_args: c_args,
    dependencies: dependencies,
    install: false
)