"""
Module to pull latest info from reddit.com/r/freeebooks
"""

import praw

AMAZON_BOOKS = {}

def browse(posts=5):
    r = praw.Reddit('Free EBook Buyer / 1.0 by frsilent')
    # while True:
    subreddit = r.get_subreddit('freeEBOOKS')
    for submission in subreddit.get_hot(limit=posts):
        if 'amazon' in submission.domain:
            print submission
            AMAZON_BOOKS[submission.name] = submission.url

if __name__ == '__main__':
    browse()
